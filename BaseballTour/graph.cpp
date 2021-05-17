/*************************************************************************
 * AUTHOR		: mar Kermiche
 * CLASS		: CS1D
 * SECTION 		: M/W 3pm
 * DUE DATE		: 4/12/17
 ************************************************************************/

#include "graph.h"

//Constructor
Graph::Graph(QString starting)
{
    smallest = 10000;
    totalDistance = 0;
    number = 0;
    crossX = 0;
    iter = 0;
    backEdge = crossX;
    numberOfNodes = V;
    listVisited = new int[numberOfNodes];
    //Initialize the City Array parallel to the graph
//    myArray.resize(t.size());
//    for(int i = 0; i < t.size(); i++)
//    {

//            myArray[i].resize(t.size());
//    }

    QString start = starting;

    QVector<StadiumInfo> temp = db.sortedByTeamStadium("Stadium");
    //qDebug("Function called");
    for(int i = 0; i < temp.size(); i++)
    {
        if(temp.at(i).stadiumName != start)
        {
            stadiumArray.push_back(temp[i].stadiumName);
        }
    }


    stadiumArray.push_front(start);


    for(int i=0; i< temp.size(); i++)    //This loops on the rows.
    {
        for(int j = 0; j<temp.size(); j++) //This loops on the columns
        {
            myArray[i][j].distance = -1;
            myArray[i][j].visited = false;
            myArray[i][j].crossed = false;
            dikeMap[i][j].totDistance = 10000000;
            dikeMap[i][j].crossed = false;
            dikeMap[i][j].local = stadiumArray[j];


        }
    }


    for(int i = 0; i < temp.size(); i++)
    {
//        qDebug() << stadiumArray[i];
        dikeMap[i][0].totDistance = 0;
        dikeMap[i][0].fromIndex = 0;
        dikeMap[i][0].index = 0;
        dikeMap[i][0].crossed = true;
    }

    cVisited.push_back(0);

}

//Destructor
Graph::~Graph() {}

//addEdge - creates a new edge in the list
void Graph::addEdge(int num1, int num2, int dist)
{
    myArray[num1][num2].distance = dist;
    myArray[num2][num1].distance = dist;
}

//Output all numbers in a matrix fashion
//void Graph::outputAll()
//{
//    for(int i = 0; i < temp.size(); i++)
//    {
//        myArray[i][0].distance = -1;
//    }

//    qDebug() << "This is the adjacency matrix: " << endl;
//    qDebug() << "\t";
//    for(int index = 0; index < temp.size(); index++)
//    {
//        qDebug() << left;
//        qDebug() << stadiumArray[index] << "  ";
//    }
//    qDebug() << endl;
//    for(int i=0; i<temp.size(); i++)    //This loops on the rows.
//    {
//        for(int j=0; j<temp.size(); j++) //This loops on the columns
//        {
//            if(myArray[i][j].distance == -1)
//            {
//                qDebug()  << "-" << "  ";
//            }
//            else
//            {
//                qDebug() << myArray[i][j].distance << "  ";
//            }
//        }
//        qDebug() << endl;
//    }
//}

QVector<CurrLocal> Graph::Dijkstras()
{
    QVector<CurrLocal> shortestPaths;
    int currI = 0;
    int nextIndex = currI;
    double prevShortest = 10000000;
    double shortestInR = prevShortest;
    QVector<StadiumInfo> temp = db.sortedByTeamStadium("Stadium");
    while(iter < V)
    {
        for(int j = 0; j < temp.size(); j++)
        {
            if(myArray[currI][j].distance != -1
            && myArray[currI][j].distance < dikeMap[currI][j].totDistance)
            {
                if(currI == 0){
                    dikeMap[currI][j].totDistance = myArray[currI][j].distance;

                    dikeMap[currI][j].index = j;

                    dikeMap[currI][j].fromIndex = currI;
                }
                else{
                    if(myArray[currI][j].distance + prevShortest
                     < dikeMap[currI][j].totDistance)
                    {
                        dikeMap[currI][j].totDistance = prevShortest
                                                  + myArray[currI][j].distance;

                        dikeMap[currI][j].index = j;

                        dikeMap[currI][j].fromIndex = currI;
                    }
                }

                //update the map for all rows containing current new distance
                for(int c = 0 ; c < temp.size(); c++)
                {
                    dikeMap[c][j].totDistance = dikeMap[currI][j].totDistance;
                    dikeMap[c][j].index = j;
                    dikeMap[c][j].fromIndex =dikeMap[currI][j].fromIndex;
                }
            }
            if(dikeMap[currI][j].totDistance < shortestInR
           && !dikeMap[currI][j].crossed
           &&  dikeMap[currI][j].totDistance != 10000000)
            {
                shortestInR = dikeMap[currI][j].totDistance;

                nextIndex = j;
            }
        }
        prevShortest = shortestInR;
        shortestInR = 1000000;

        currI = nextIndex;

        for(int i = 0; i < temp.size(); i++)
        {
            dikeMap[i][currI].crossed = true;
        }
        iter++;
    }

    for(int i = 0; i < temp.size(); i++)
    {
        shortestPaths.push_back(dikeMap[currI][i]);
    }

    return shortestPaths;
}

// =======================================================================
// DFS

//int Graph::DFS(QString startingStadium, QVector<QString> &dfs)
//{
//// verticesVisited
////    int numVisited = 0; // Number of vertices visited.

////       // Iterator to the first vertex in the graph.
////       QVector<Vertex>::iterator graphIt = graph.begin();

////       // Counts the number of vertices in the graph that are marked as visited.
////       while(graphIt != graph.end())
////       {
////           if(graphIt->visited)
////           {
////               numVisited++;
////           }

////           graphIt++;
////       }

////       return numVisited;


//    if(verticesVisited() == graph.size())
//    {
//        for (int i=0; i<graph.size(); i++)
//        {
//            graph[i].visited = false;
//            for (int j=0; j< graph.at(i).edgeList.size(); j++)
//            {
//                graph[i].edgeList[j].discoveryEdge = false;
//            }
//        }

//        dfsDistance = 0;
//        mstDistance = 0;
//    }


//    // Gets the graph index of the vertex being visited.
//    int currVertex = findVertex(startingStadium);

//    // Visits the vertex.
//    graph[currVertex].visited = true;

//    // Searches the vector of visited vertices for the stadium being visited.
//    QVector<QString>::iterator nextStadiumIt = find(dfs.begin(), dfs.end(), startingStadium);

//    // Adds the vertex to the vector if it is not already in the vector.
//    if(nextStadiumIt == dfs.end())
//    {
//        dfs.push_back(startingStadium);
//    }

//    // Performs a recursive call on itself to visit all vertices in the graph.
//    if(verticesVisited() != graph.size())
//    {
//        // Gets the graph index of the next closest stadium in the graph.
//        int nextVertex = smallestEdgeDFS(currVertex, dfs);

//        // Performs recursive call to visit the next closest stadium.
//        DFS(graph.at(nextVertex).stadium, dfs);
//    }

//    return dfsDistance;
//}


