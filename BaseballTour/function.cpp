
#include "db.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void readFile(vector<City> &DB)
{
    fstream infile;
    //Reminder: inputNames must have a number of strings EXACTLY EQUAL to the number of desired items in the database
    infile.open("inputNames.txt");
    double doubleInput;
    string stringInput;

    City *input = new City;

    while(getline(infile, stringInput))
    {
        input -> setName(stringInput);
        DB.push_back(*input);

    }
    infile.close();
    //
    // some input file name
    //
    infile.open("inputSouvenirs.txt");
    for(unsigned int i = 0; i < DB.size(); i++)
    {
        for(int j = 0; j < 7; j++)
        {
            getline(infile, stringInput);
            infile >> doubleInput;
            infile.ignore(100000, '\n');
            DB.at(i).setFood(stringInput, doubleInput, j);
        }
    }
    infile.close();










    //
    // some input file name
    //
    infile.open("inputDistances.txt");

    for(unsigned int i = 0; i < DB.size(); i++)
    {
        for(unsigned int j = 0; j < DB.size() - 1; j++)
        {
            getline(infile, stringInput);
//            cout << stringInput << endl;
            infile >> doubleInput;
            infile.ignore(100000, '\n');
            DB.at(i).addDistance(stringInput, doubleInput);
        }
    }
    infile.close();

}

void City::setName(string name)
{
    city = name;
}

string City::getName()
{
    return city;
}

void City::setFood(string a, double b, int index)
{
    foods[index].foods = a;
    foods[index].cost = b;
}

void City::printFood()
{
    for(int i = 0; i < 7; i++)
    {
        cout << foods[i].foods << " " << foods[i].cost << "$ -> ";
    }
}

void City::printDistances()
{
    for(unsigned int i = 0; i < otherCites.size(); i++)
    {
        cout << otherCites.at(i).endCity << " " << otherCites.at(i).kilometers << " -> ";
    }
}

void City::addDistance(string a, double b)
{
    Distances *newDistances = new Distances;
    newDistances -> endCity = a;
    newDistances -> kilometers = b;
    otherCites.push_back(*newDistances);
}

food City::getFood(int i)
{
    return foods[i];
}

Distances City::getDistances(int i)
{
    return otherCites.at(i);
}
void City::purchase(food item)
{
    if(item.cost !=0)
        numPurchased++;
    totalSpent += item.cost;
    std::cout<<"TotalSpent = " << totalSpent << endl;
}
double City::getTotalSpent()
{
    return totalSpent;
}
int City::getNumPurchased()
{
    return numPurchased;
}

void addCity(vector<City> &DB)
{
    City a;
    a.setAll(DB);
    DB.push_back(a);
}

void City::addFood(food a)
{
    int i = 0;
    food current = foods[i];
    while(current.foods != "a")
    {
        current = foods[i];
        i++;
    }
    foods[i] = a;
}

void City::removeFood(int i)
{
    food current = foods[i];
    int j = i;
    while(current.foods != "a")
    {
        current = foods[j];
        j++;
    }
    foods[i].foods = foods[j - 1].foods;
    foods[i].cost = foods[j - 1].cost;
    foods[j].foods = "a";
}

void City::setAll(vector<City> &DB)
{
    string stringInput;
    double doubleInput;
    int s = 0;

    cout << "Input the college name: ";
    getline(cin, stringInput);
    city = stringInput;

    stringInput = "i"; //To avoid error if the college name is 'a'

    while(stringInput != "a" && s != 7)
    {
        cout << "Enter a souvenir (Enter 'a' to exit early): ";
        getline(cin, stringInput);
        cout << "Enter the souvenirs price: ";
        cin >> doubleInput;
        cin.ignore(10000, '\n');
        foods[s].foods = stringInput;
        foods[s].cost = doubleInput;
    }

    for(unsigned int j = 0; j < DB.size() - 1; j++)
    {
        cout << "how far is this college from " << DB.at(j).city << "? ";
        cin >> doubleInput;
        cin.ignore(10000, '\n');
    }
}
void addCollege(vector<City> &DB, string file)
{
    fstream infile;
    infile.open(file);

    if(infile.good())//making sure the file has data in it to read
    {
        City newCollege;
        string stringInput;
        double doubleInput;

        while(getline(infile, stringInput))//until we cant read another name
        {
            newCollege.setName(stringInput);
            DB.push_back(newCollege);
            for(int j = 0; j < 7; j++)
            {
                getline(infile, stringInput);
                infile >> doubleInput;
                infile.ignore(100000, '\n');
                DB.at(DB.size()-1).setFood(stringInput, doubleInput, j);
            }
            for(unsigned int j = 0; j < DB.size() - 1; j++)
            {
                getline(infile, stringInput);
                infile >> doubleInput;
                infile.ignore(100000, '\n');
                DB.at(DB.size() - 1).addDistance(stringInput, doubleInput);
                DB.at(j).addDistance(DB.at(DB.size()-1).getName(), doubleInput);
            }
        }
    }
    else
    {

    }
}
void saveFiles(vector<City> &DB)
{
    fstream file1;
    fstream file2;
    fstream file3;

    file1.open("inputNames.txt");
    for(unsigned int i = 0; i < DB.size(); i++)
    {
        if(i == DB.size() - 1)
        {
            file1 << DB.at(i).getName();
        }
        else
        {
        file1 << DB.at(i).getName() << endl;
        }
    }
    file1.close();
    file2.open("inputSouvenirs.txt");
    for(unsigned int i = 0; i < DB.size(); i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(i == DB.size() - 1 && j == 6)
            {
                file2 << DB.at(i).getFood(j).foods << endl;
                file2 << DB.at(i).getFood(j).cost;
            }
            else
            {
            file2 << DB.at(i).getFood(j).foods << endl;
            file2 << DB.at(i).getFood(j).cost << endl;
            }
        }
    }

    file2.close();
    file3.open("inputDistances.txt");
    for(unsigned int i = 0; i < DB.size(); i++)
    {
        for(unsigned int j = 0; j < DB.size() - 1; j++)
        {
            file3 << DB.at(i).getDistances(j).endCity << endl;
            if(i == DB.size() - 1 && j == DB.size() - 2)
            file3 << DB.at(i).getDistances(j).kilometers;
            else
            file3 << DB.at(i).getDistances(j).kilometers << endl;
        }
    }

}
