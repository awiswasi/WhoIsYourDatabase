#ifndef GRAPHS_H
#define GRAPHS_H

// C++ program to print DFS traversal from a given vertex in a  given graph
#include <iostream>
#include <iomanip>
#include <QString>
#include <map>
#include <list>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <iterator>
#include <QString>
#include <queue>
#include <deque>
#include <functional>
#include "dbmanager.h"

using namespace std;
       // number of nodes

const int V = 31;
//Distance object in the multidimensional array
struct DistObject
{
    int distance;
    bool visited;
    bool crossed;
};

struct CurrLocal
{
    QString local;
    QString from;
    int index;
    int fromIndex;
    double totDistance;
    bool crossed;
};

struct Cust2
{
    QString stad;
    int distance;
};

struct stadArr
{
    QString stadium;
    int index;
};

class Graph												// Graph class
{
private:
    int vertexCount = 0;
    int numberOfNodes;									// number of nodes
    int smallest;
    int crossX;
    int backEdge;
    int *listVisited;
    dbManager db;
    QVector<int> cVisited;
    QQueue<int>listCrossed;
    int number;
    int iter;
    int totalDistance;							// Total distance travelled
    DistObject myArray[V][V];
    CurrLocal dikeMap[V][V];
    QVector<QString> stadiumArray;

public:
    Graph() {}
    Graph(QString starting);  	 				  		  		// Constructor
    ~Graph();							  		// Destructor

    //ADD & OUTPUT
    void addEdge(int num1, int num2, int dist);// f to add an edge to graph
    void outputAll();					// Output as simple distance matrix

    QVector<int> CityDijkstra(int src)
    {
        const int SIZE = 30;
        QVector<int> dist;
    }

    QVector<CurrLocal> Dijkstras();

    /*************************************************************************************************************************************************************
     *************************************************************************************************************************************************************/

    // A function to find the vertex with minimum distance value, from
    // the set of vertices not yet included in shortest path tree
    int minDistance(int dist[], bool sptSet[])
    {
       // Initialize min value
       int min = INT_MAX, min_index;

       for (int v = 0; v < V; v++)
         if (sptSet[v] == false && dist[v] <= min)
             min = dist[v], min_index = v;

       return min_index;
    }


    QVector<int> dijkstra2(int src)
    {
         int dist[V];     // The output array.  dist[i] will hold the shortest
                          // distance from src to i
         QVector<QString> nameInd;
         bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                         // path tree or shortest distance from src to i is finalized

         // Initialize all distances as INFINITE and stpSet[] as false
         for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

         // Distance of source vertex from itself is always 0
         dist[src] = 0;

         // Find shortest path for all vertices
         for (int count = 0; count < V-1; count++)
         {
           // Pick the minimum distance vertex from the set of vertices not
           // yet processed. u is always equal to src in first iteration.
           int u = minDistance(dist, sptSet);

           // Mark the picked vertex as processed
           sptSet[u] = true;

           // Update dist value of the adjacent vertices of the picked vertex.
           for (int v = 0; v < V; v++)

             /* Update dist[v] only if is not in sptSet, there is an edge from
                u to v, and total weight of path from src to  v through u is
                smaller than current value of dist[v] */
             if (!sptSet[v] && myArray[u][v].distance && dist[u] != INT_MAX
                                           && dist[u]+myArray[u][v].distance < dist[v]){
                 dist[v] = dist[u] + myArray[u][v].distance;
                 qDebug() << myArray[u][v].distance;
             }

         }

         QVector<int> vDist;

         for(int i = 0; i < V; i++){
             vDist.push_back(dist[i]);

         }
         return vDist;
    }
    /*************************************************************************************************************************************************************
     *************************************************************************************************************************************************************/

    QVector<QString> ReturnCityArray() const
    {
        QVector<QString> cities;
        for(int i = 0; i < numberOfNodes; i++)
        {
            cities.push_back(stadiumArray[i]);
        }

        return cities;
    }
    int FindIndex(QString stadium)
    {
        int i = 0;
        bool found = false;

        while(!found && i < stadiumArray.size())
        {
            if(stadiumArray[i] == stadium){
                found = true;

                return i;
            }

            i++;
        }

        return -1;
    }
    //Traversals using algorithms
};


#endif // GRAPHS_H
