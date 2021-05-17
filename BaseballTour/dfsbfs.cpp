#include "dfsbfs.h"
#include "ui_dfsbfs.h"
#include <QDebug>
#include <stack>
#include <algorithm>

dfsbfs::dfsbfs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dfsbfs)
{
    ui->setupUi(this);
    smallest = 10000;
        totalDistance = 0;
        number = 0;
        crossX = 0;
        iter = 0;
        numberOfNodes = 12;
        backEdge = crossX;
        //Initialize the City Array parallel to the graph
        cityArray[0] = "Seattle";
        cityArray[1] = "Chicago";
        cityArray[2] = "Boston";
        cityArray[3] = "New York";
        cityArray[4] = "Atlanta";
        cityArray[5] = "Miami";
        cityArray[6] = "Houston";
        cityArray[7] = "Dallas";
        cityArray[8] = "Kansas City";
        cityArray[9] = "Denver";
        cityArray[10]= "San Francisco";
        cityArray[11]= "Los Angeles";

        for(int i=0; i<numberOfNodes; i++)    //This loops on the rows.
        {
            for(int j=0; j<numberOfNodes; j++) //This loops on the columns
            {
                myArray[i][j].distance = -1;
                myArray[i][j].visited = false;
                myArray[i][j].crossed = false;
            }
        }




        cVisited.push_back(0);

        /*****************************************************************
            * CONSTANTS
            * ---------------------------------------------------------------
            * USED FOR CLASS HEADINGS - ALL WILL BE OUTPUT
            * ---------------------------------------------------------------
            * PROGRAMMER : Programmer's Name
            * CLASS		 : Student's Course
            * SECTION	 : Class Days and Times
            * LAB_NUM	 : Lab Number (specific to this lab)
            * LAB_NAME   : Title of the Lab
            * ----------------------------------------------------------------
            ****************************************************************/
                //Constant Declarations
//                const string PROGRAMMER = "Halley Bradt & Omar Kermiche";
//                const string CLASS 	 	= "CS1D";
//                const string SECTION 	= "M/W 3pm";
//                const int LAB_NUM	 	=  10;
//                const string LAB_NAME 	= "Graphs, BFS, DFS";

                //Calls the function PrintHeader to output the author box
//                PrintHeader(PROGRAMMER, CLASS, SECTION,LAB_NUM, LAB_NAME, 'A', cout);

                //Description
//                cout << "The purpose of the lab is to show the the implem. of \n"
//                        "of a graph and traversals breadth first and depth first\n"
//                        "This will demonstrate knowledge of graphs and \n"
//                        "functions that enable the graph ADT\n\n";

            //Variable Declaration
            dfsbfs myGraph;		//To be worked on later

            // Create a graph given in the above diagram

            //The 2 numbers are used from their indices in cityArray
            myGraph.addEdge(0, 1, 2097);
            myGraph.addEdge(1, 2, 983);
            myGraph.addEdge(2, 3, 214);
            myGraph.addEdge(3, 4, 888);
            myGraph.addEdge(4, 5, 661);
            myGraph.addEdge(5, 6, 1187);
            myGraph.addEdge(6, 7, 239);
            myGraph.addEdge(7, 8, 496);
            myGraph.addEdge(8, 9, 599);
            myGraph.addEdge(9, 10, 1267);
            myGraph.addEdge(10, 11, 381);
            myGraph.addEdge(0, 9, 1331);
            myGraph.addEdge(0, 10, 807);
            myGraph.addEdge(1, 9, 1003);
            myGraph.addEdge(1, 8, 533);
            myGraph.addEdge(1, 3, 787);
            myGraph.addEdge(3, 8, 1260);
            myGraph.addEdge(4, 8, 864);
            myGraph.addEdge(4, 7, 781);
            myGraph.addEdge(4, 6, 810);
            myGraph.addEdge(7, 11, 1435);
            myGraph.addEdge(8, 11, 1663);
            myGraph.addEdge(9, 11, 1015);

            //Output everything in a matrix formation
            myGraph.outputAll();

            //Output everything in the DFS formation
            cout << "\nImplementing DFS... starting at Seattle\n";
            myGraph.DFS(0,0);

        //	//Output everything in the BFS formation
            cout << "\n\nImplementing BFS... starting at Seattle\n";
            myGraph.BFS(0,0);
}

dfsbfs::~dfsbfs()
{
    delete ui;
}
//addEdge - creates a new edge in the list
void dfsbfs::addEdge(int num1, int num2, int dist)
{
    myArray[num1][num2].distance = dist;
    myArray[num2][num1].distance = dist;
}

//Output all numbers in a matrix fashion
void dfsbfs::outputAll()
{
    cout << "This is the adjacency matrix: " << endl;
    cout << "\t";
    for(int index = 0; index < 12; index++)
    {
        cout << left;
        cout << setw(14) << cityArray[index];
    }
    cout << endl;
    for(int i=0; i<12; i++)    //This loops on the rows.
    {
        cout << setw(14) << cityArray[i];
        for(int j=0; j<12; j++) //This loops on the columns
        {
            if(myArray[i][j].distance == -1)
            {
                cout << setw(14) << "-";
            }
            else
            {
                cout << setw(14) << myArray[i][j].distance;
            }
        }
        cout << endl;
    }
}

//DFSUtil - checks if it was visited, recurs for all vertices
void dfsbfs::DFSUtil(int Xcoordinate, int Ycoordinate)
{
    smallest = 10000;			//Number to compare against
    int tempX;					//The temporary X variable
    bool possible = false;		//Whether it is possible to visit a city
    int tempY;					//The temporary Y variable

    //Go through the first column
    for(int i = 0; i < 12; i++)
    {
        //If the node is not visited, distance exists, and it is smaller
        if(myArray[Xcoordinate][i].visited == false &&
           myArray[Xcoordinate][i].distance > -1 &&
           myArray[Xcoordinate][i].distance < smallest)
        {
            //make smallest the new distance
            smallest = myArray[Xcoordinate][i].distance;
            tempX = Xcoordinate;
            tempY = i;
            possible = true;
        }
    }

    //If all the cities have been visited
    if(number == 11)
    {
        //Return to the main
        return;
    }
    //If it is not possible to visit, backtrack
    else if(!possible)
    {
        cout << "Back Edge: " << cityArray[listVisited[iter-1]] << endl;
        iter = iter - 1;
        DFSUtil(listVisited[iter], 0);
    }
    //Otherwise, mark the paths as visited, as well add up the
    //total distance and output
    else
    {

        cout << "Discovery edge: ";
        //Add up the distances
        totalDistance = totalDistance + smallest;

        //Output the node visited
        cout << setw(15) << left << cityArray[tempX];
        cout << setw(5)  << "--->";
        cout << setw(15) << left << cityArray[tempY];

        myArray[tempX][tempY].visited = true;
        myArray[tempY][tempX].visited = true;
        cVisited.push_back(tempY);

        // Mark the current city as visited for all rows in the matrix
        for(unsigned int col = 0; col < cVisited.size(); col++)
        {
            for(int row = 0; row < 12; row++)
            {
                if(myArray[row][cVisited[col]].distance != -1)
                {
                    myArray[row][cVisited[col]].visited = true;
                }
            }
        }

        //Place into the list visited the number corresponding to the city
        listVisited[number] = tempY;
        number++;
        iter++;

        //Output the distance for the trip
        cout << setw(10) << left << myArray[tempX][tempY].distance;
        cout << endl << flush;

        //Recursively call the function again, this time using
        //The next city in the trip
        DFSUtil(tempY,0);
    }
}

void dfsbfs::BFSUtil(int xCd, int yCd)
{
    smallest = 10000;	  //Number to compare against
    bool possible = false;//Whether it is possible to visit a city

    //Go through the row
    for(int i = 0; i < 12; i++)
    {
        //If the node is not visited, distance exists, and it is smaller
        if(copy[xCd][i].crossed == false &&
           copy[xCd][i].distance > -1)
        {
            possible = true;
        }
    }

    //If all the cities have been visited
    if(number == 12)
    {
        //Return to the main
        return;
    }
    else if(!possible)
    {
        listCrossed.push(backEdge);

        if(cityArray[xCd] != cityArray[listCrossed.front()])
        {
            cout << "\nCross Edge: ";
            //Output the node crossed
            cout << endl << cityArray[xCd] << " " << flush;
            cout << "-->"<< cityArray[listCrossed.front()] << " " << flush << endl;
            BFSUtil(listCrossed.front(), 0);
        }

    }
    else
    {
        PrintAdjEdges(xCd);

        if(cityArray[xCd] != cityArray[listCrossed.front()])
        {
            cout << "\nCross Edge: ";
            //Output the node crossed
            cout << endl << cityArray[xCd] << " " << flush;
            cout << "-->"<< cityArray[listCrossed.front()] << " " << flush
                 << endl;
        }
        crossX = listCrossed.front();

        backEdge = crossX;

        for(int row = 0; row < 12; row++)
        {
            copy[row][crossX].crossed = true;
        }

        listCrossed.pop();

        BFSUtil(crossX, 0);
    }
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void dfsbfs::DFS(int Xcoordinate, int Ycoordinate)
{
    // Call the recursive helper function to print DFS traversal
    DFSUtil(Xcoordinate, Ycoordinate);

    //cout << "Total mileage gone: " << totalDistance << endl;
    QString str = QString::number(totalDistance);
    ui->dfs_answer_label->setText(str);
}

void dfsbfs::BFS(int xCd, int yCd)
{
    totalDistance = 0;
    number = 1;
    cVisited.clear();
    for(int i=0; i<numberOfNodes; i++)    //This loops on the rows.
    {
        listVisited[i] = 0;

        for(int j=0; j<numberOfNodes; j++) //This loops on the columns
        {
            myArray[i][j].visited = false;
            copy[i][j] = myArray[i][j];
        }
    }

    for(int row = 0; row < 12; row++)
    {
        copy[row][crossX].crossed = true;
        copy[row][crossX].visited = true;
    }
    BFSUtil(xCd, yCd);

    QString str = QString::number(totalDistance);
    ui->bfs_answer_label->setText(str);
}

void dfsbfs::PrintAdjEdges(int xCd)
{
    unsigned int indexCurrent;
    int indexCheck;
    CurrCity tempLargerCheck;
    string tempStringLarger;

    vector<CurrCity> currVisit;

    for(int i = 0; i < 12; i++)
    {
        CurrCity n;

        if(copy[xCd][i].visited == false && copy[xCd][i].distance != -1)
        {
            n.city = cityArray[i];
            n.index = i;
            n.distance = copy[xCd][i].distance;

            currVisit.push_back(n);
            number++;
        }
    }

    //sort the soon to be discovered cities in vector
    for(indexCurrent = 0;indexCurrent < currVisit.size();indexCurrent++)
    {
        indexCheck = indexCurrent;

        while(indexCheck>0
           && currVisit[indexCheck].distance
            < currVisit[indexCheck - 1].distance)
        {
            tempLargerCheck = currVisit[indexCheck];
            currVisit[indexCheck]= currVisit[indexCheck - 1];
            currVisit[indexCheck - 1] = tempLargerCheck;
            indexCheck--;
        }
    }
    for(unsigned int i = 0; i < currVisit.size(); i++)
    {
        cout << "Discovery edge: ";
        //Add up the distances
        totalDistance = totalDistance + currVisit[i].distance;

        listCrossed.push(currVisit[i].index);

        //Output the node visited
        cout << setw(15) << left << cityArray[xCd] << " " << flush;
        cout << setw(5) << "-->";
        cout << setw(15) << left<< currVisit[i].city << " " << flush;

        //Output the distance for the trip
        cout << setw(10) << left << currVisit[i].distance << " "
             << flush;
        cout << endl << flush;

        cVisited.push_back(currVisit[i].index);
    }

    // Mark the current city as visited for all rows in the matrix
    for(unsigned int col = 0; col < cVisited.size(); col++)
    {
        for(int row = 0; row < 12; row++)
        {
            copy[row][cVisited[col]].visited = true;
        }
    }
}
