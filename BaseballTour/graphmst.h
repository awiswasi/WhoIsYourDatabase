#ifndef GRAPHMST_H
#define GRAPHMST_H


#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <QVector>
#include <QTextBrowser>
#include <sstream>
#include "stadiumstructs.h"
#include <qdebug.h>

using namespace std;

const int MAX_CITIES = 32;

class graphmst
{
public:

    // Constructor
    graphmst();

    // Destructor
    ~graphmst();

    // MUTATORS
    void insertEdge(const QString inCity1, const QString inCity2, const int inDistance);
    void insertVertex(const QString inCity);

    //Accessors
    void primMST(QTextBrowser *inTable);
    void ReadInfo(QVector<DistanceInfo> edgeList);
    bool CityExists(const QString& inCity);
    void DisplayMST(int parent[], int n, QTextBrowser *inTable);

private:
    int vertexCount;
    QString vertexList[MAX_CITIES];
    int graph[MAX_CITIES][MAX_CITIES];

    int minKey(int key[], bool mstSet[]);

};


#endif // GRAPHMST_H
