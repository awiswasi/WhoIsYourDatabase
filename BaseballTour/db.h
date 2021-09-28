#include <string>
#include <vector>
using namespace std;

#ifndef DB_H
#define DB_H

#include <QDialog>

struct food
{
    //does the data match?
    string foods;
    double cost;
};
struct Distances
{
    // does the data match?
    string endCity;
    double kilometers;
};
class City
{
    private:
        double totalSpent = 0;
        int numPurchased = 0;

        string city;
        vector<Distances> otherCites;
        food foods[7];
        City *next;
    public:
        double distanceTraveled = 0;
        food getFood(int);                  // what would returning a struct do for us | to be able to print the souvenir list
        Distances getDistances(int);                // what would returning a struct do for us | to be able to print the distances to each college
        void setName(string);
        void setFood(string, double, int);
        void addDistance(string, double);
        string getName();
        void printFood();
        void printDistances();
        void purchase(food);
        double getTotalSpent();
        int getNumPurchased();
        void addFood(food);
        void removeFood(int);
        void setAll(vector<City> &DB);
};

void readFile(vector<City> &);
void addCollege(vector<City> &, string file);
void saveFiles(vector<City> &DB);

#endif // DB_H
