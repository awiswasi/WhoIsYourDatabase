#include "graphmst.h"

// constructor
graphmst::graphmst()
{
    vertexCount = 0;

    // Initializing all city names to a blank space
    for (int index = 0; index < MAX_CITIES; index++)
    {
        vertexList[index] = " ";
    }


    // initializing all distances to 0
    for (unsigned int row = 0; row < MAX_CITIES; row++)
    {
        for (unsigned int col = 0; col < MAX_CITIES; col++)
        {
            graph[row][col] = 0;
        }
    }

}

// destructor
graphmst::~graphmst(){}


void graphmst::insertEdge(const QString inCity1, const QString inCity2, const int inDistance)
{
    int row = 0;
    int col = 0;
    bool found = false;


    // finding where to insert (row should be inCity1, col should be inCity2)
    while (row < MAX_CITIES && !found)
    {
        while (col < MAX_CITIES && !found)
        {
            if (vertexList[row] == inCity1 && vertexList[col] == inCity2)
            {
                found = true;

                // stores the distance between i and j
                graph[row][col] = inDistance;
                graph[col][row] = inDistance;

            }
            else
            {
                col++;
            }
        }

        // resetting columns
        col = 0;

        if(!found)
        {
            row++;
        }
    }

    if (!found)
    {
        cout << "\n\nMUST INSERT CITIES FIRST\n\n";
    }
}


void graphmst::insertVertex(const QString inCity)
{

    if (vertexCount != MAX_CITIES)
    {
        vertexList[vertexCount] = inCity;
        vertexCount++;
    }
    else
    {
        cout << "\n\nGraph is full!\n\n";
    }
}


// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int graphmst::minKey(int key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < MAX_CITIES; v++)
   {
       if (mstSet[v] == false && key[v] < min)
       {
           min = key[v], min_index = v;
       }
   }


   return min_index;
}



void graphmst::DisplayMST(int parent[], int n, QTextBrowser *inTable)
{

        int totalDistance = 0;
        stringstream ss;

        ss << left;

        ss << "Creating MST and printing edges and total mileage...\n\n";
        ss << "(FORMAT INFORMATION)\n";
        ss << setw(14) << "Initial City" << "---->  "
             << setw(14) << "Ending City" << "   - Distance: (Distance between)";
        ss << "\n\n";


        for (int index = 1; index < vertexCount; index++)
        {
            ss << setw(14) << vertexList[parent[index]].toStdString() << "---->  "
                 << setw(14) << vertexList[index].toStdString() << "   - Distance: " << graph[parent[index]][index];
            ss << "\n";

            totalDistance += graph[parent[index]][index];
        }

        ss << "\nTotal Distance: " << totalDistance << endl;


        ss << right;

        inTable->setText(QString::fromStdString(ss.str()));
}


// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void graphmst::primMST(QTextBrowser *inTable)
{
     int parent[vertexCount]; // Array to store constructed MST
     int key[vertexCount];   // Key values used to pick minimum weight edge in cut
     bool mstSet[vertexCount];  // To represent set of vertices not yet included in MST

     // Initialize all keys as INFINITE
     for (int i = 0; i < vertexCount; i++)
     {
         key[i] = INT_MAX, mstSet[i] = false;
     }

     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST

     // The MST will have MAX_CITIES vertices
     for (int count = 0; count < vertexCount-1; count++)
     {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < vertexCount; v++)
        {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
           if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
           {
              parent[v]  = u, key[v] = graph[u][v];
           }
        }

     }

     // print the constructed MST
     DisplayMST(parent, vertexCount, inTable);
}


bool graphmst::CityExists(const QString& inCity)
{
    bool found = false;
    int index = 0;

    while (index < MAX_CITIES && !found)
    {
        if (vertexList[index] == inCity)
        {
            found = true;
        }
        else
        {
            index++;
        }
    }

    return found;


}


void graphmst::ReadInfo(QVector<DistanceInfo> edgeList)
{

    // Reading in city names
    for (int index = 0; index < edgeList.size(); index++)
    {
        if (!CityExists(edgeList[index].startStad))
        {
            insertVertex(edgeList[index].startStad);
        }
    }




    // Reading in edges
    for (int index = 0; index < edgeList.size(); index++)
    {
        insertEdge(edgeList[index].startStad, edgeList[index].endStad, edgeList[index].distance);
    }
}
