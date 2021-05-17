#ifndef DFSBFS_H
#define DFSBFS_H

#include <QDialog>
#include <QString>
#include <QtAlgorithms>
#include <vector>
#include <map>
#include <iostream>

#include <iomanip>
#include <string>
#include <map>
#include <list>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <iterator>
#include <string>
#include <queue>
#include <deque>
#include <functional>
using namespace std;

using namespace std;
namespace Ui {
class dfsbfs;
}

class dfsbfs : public QDialog
{
    Q_OBJECT

public:
    struct DistObject
    {
        int distance;
        bool visited;
        bool crossed;
    };

    struct CurrCity
    {
        string city;
        int index;
        int distance;
    };

    explicit dfsbfs(QWidget *parent = nullptr);
    ~dfsbfs();

    /*Graph();  	 				  		  		// Constructor
       ~Graph();*/							  		// Destructor

       //ADD & OUTPUT
       void addEdge(int num1, int num2, int dist);// f to add an edge to graph
       void outputAll();					// Output as simple distance matrix

       //Traversals using algorithms
       void DFS(int Xcoordinate, int Ycoordinate); // DFS trav of the vert from V
   void BFS(int xCd, int yCd);

private:
    Ui::dfsbfs *ui;
    int numberOfNodes;									// number of nodes
        int smallest;
        int crossX;
        int backEdge;
        int listVisited[12];
        vector<int> cVisited;
        queue<int>listCrossed;
        int number;
        int iter;
        int totalDistance;							// Total distance travelled
        DistObject myArray[12][12];					// Adjacency Matrix
        DistObject copy[12][12];
        string cityArray[12];						// Corresponding names
        void PrintAdjEdges(int xCd);
        void DFSUtil(int Xcoordinate, int Ycoordinate); // A function used by DFS
        void BFSUtil(int xCd, int yCd);
};

#endif // DFSBFS_H
