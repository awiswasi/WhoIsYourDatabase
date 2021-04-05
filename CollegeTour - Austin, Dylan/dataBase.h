/*
 * dataBase.h
 *
 *  Created on: Feb 19, 2021
 *      Author: liame
 */

#include <string>
#include <vector>
using namespace std;

#ifndef DATABASE_H_
#define DATABASE_H_

struct Souvenir
{
	string souvenir;
	double cost;
};

struct Distances
{
    // data
    string endingCollege;
    double distanceBetween;
};

//vector of type College or linked list of type College
class College
{
    private:
        double totalSpent = 0;
        int numPurchased = 0;

		string collegeName;
        vector<Distances> otherColleges;
        Souvenir souvenirs[7];
        College *next;

    public:
       double distanceTraveled = 0;
       Souvenir getSouvenir(int);                  // what would returning a struct do for us | to be able to print the souvenir list
       Distances getDistances(int);                // what would returning a struct do for us | to be able to print the distances to each college
       void setName(string);
       void setSouvenir(string, double, int);
       void addDistance(string, double);
       string getName();
       void printSouvenirs();
       void printDistances();
       void purchase(Souvenir);
       double getTotalSpent();
       int getNumPurchased();
       void addSouvenir(Souvenir);
       void removeSouvenir(int);
       void setAll(vector<College> &DB);


};

//The readFile should be outside the class so that we can easily read into the whole database without ridiculous complications
void readFile(vector<College> &);
void addCollege(vector<College> &, string file);
void saveFiles(vector<College> &DB);
#endif /* DATABASE_H_ */
