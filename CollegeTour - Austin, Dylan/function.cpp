/*
 * function.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: liame
 */

#include "dataBase.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//This function takes in a vector of Colleges and fills them with text input
/************************************************************************************************************
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! *
 ************************************************************************************************************
 * This function has 5 assumptions:
 * 		the vector is currently empty
 * 		the count given is equal to 0
 * 		All of the input files have information for at least one college
 * 		All of the input files are formated correctly
 * 	In addition this function requires a text file named "inputNames.txt"
 *		And a text file named inputDistances.txt
 *		And a text file named inputSouvenirs.txt
 *
 ************************************************************************************************************
 *	inputSouvenirs MUST have a string and a double on every 2 lines. when no souvenir is desired for a line *
 *	use "a"                                                                                                 *
 *	inputDistances is the same in this regard                                                               *
 ************************************************************************************************************
 */

void readFile(vector<College> &DB)
{
	fstream infile;
	//Reminder: inputNames must have a number of strings EXACTLY EQUAL to the number of desired items in the database
	infile.open("inputNames.txt");
	double doubleInput;
	string stringInput;

	College *input = new College;

	while(getline(infile, stringInput))
	{
		input -> setName(stringInput);
		DB.push_back(*input);

	}
	infile.close();
	//Reminder: each item in the database MUST have enough strings and double for 7 souvenirs EACH in inputSouvenirs
	infile.open("inputSouvenirs.txt");
	for(unsigned int i = 0; i < DB.size(); i++)
	{
		for(int j = 0; j < 7; j++)
		{
			getline(infile, stringInput);
			infile >> doubleInput;
			infile.ignore(100000, '\n');
			DB.at(i).setSouvenir(stringInput, doubleInput, j);
		}
	}
	infile.close();
	//Reminder: input distances MUST have enough strings and doubles (equal to DB.size()^2)
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

void College::setName(string name)
{
	collegeName = name;
}

string College::getName()
{
	return collegeName;
}

void College::setSouvenir(string a, double b, int index)
{
	souvenirs[index].souvenir = a;
	souvenirs[index].cost = b;
}

void College::printSouvenirs()
{
	for(int i = 0; i < 7; i++)
	{
		cout << souvenirs[i].souvenir << " " << souvenirs[i].cost << "$ -> ";
	}
}

void College::printDistances()
{
	for(unsigned int i = 0; i < otherColleges.size(); i++)
	{
		cout << otherColleges.at(i).endingCollege << " " << otherColleges.at(i).distanceBetween << " -> ";
	}
}

void College::addDistance(string a, double b)
{
	Distances *newDistances = new Distances;
	newDistances -> endingCollege = a;
	newDistances -> distanceBetween = b;
	otherColleges.push_back(*newDistances);
}

Souvenir College::getSouvenir(int i)
{
    return souvenirs[i];
}

Distances College::getDistances(int i)
{
    return otherColleges.at(i);
}
void College::purchase(Souvenir item)
{
    if(item.cost !=0)
        numPurchased++;
    totalSpent += item.cost;
    std::cout<<"TotalSpent = " << totalSpent << endl;
}
double College::getTotalSpent()
{
    return totalSpent;
}
int College::getNumPurchased()
{
    return numPurchased;
}

void addCollege(vector<College> &DB)
{
	College a;
	a.setAll(DB);
	DB.push_back(a);
}

void College::addSouvenir(Souvenir a)
{
	int i = 0;
	Souvenir current = souvenirs[i];
	while(current.souvenir != "a")
	{
		current = souvenirs[i];
		i++;
	}
	souvenirs[i] = a;
}

void College::removeSouvenir(int i)
{
	Souvenir current = souvenirs[i];
	int j = i;
	while(current.souvenir != "a")
	{
		current = souvenirs[j];
		j++;
	}
	souvenirs[i].souvenir = souvenirs[j - 1].souvenir;
	souvenirs[i].cost = souvenirs[j - 1].cost;
	souvenirs[j].souvenir = "a";
}

void College::setAll(vector<College> &DB)
{
	string stringInput;
	double doubleInput;
	int s = 0;

	cout << "Input the college name: ";
	getline(cin, stringInput);
	collegeName = stringInput;

	stringInput = "i"; //To avoid error if the college name is 'a'

	while(stringInput != "a" && s != 7)
	{
		cout << "Enter a souvenir (Enter 'a' to exit early): ";
		getline(cin, stringInput);
		cout << "Enter the souvenirs price: ";
		cin >> doubleInput;
		cin.ignore(10000, '\n');
		souvenirs[s].souvenir = stringInput;
		souvenirs[s].cost = doubleInput;
	}

    for(unsigned int j = 0; j < DB.size() - 1; j++)
    {
    	cout << "how far is this college from " << DB.at(j).collegeName << "? ";
		cin >> doubleInput;
		cin.ignore(10000, '\n');
    }


}
void addCollege(vector<College> &DB, string file)
{
	fstream infile;
	infile.open(file);

	if(infile.good())//making sure the file has data in it to read
	{
		College newCollege;
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
				DB.at(DB.size()-1).setSouvenir(stringInput, doubleInput, j);
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
void saveFiles(vector<College> &DB)
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
                file2 << DB.at(i).getSouvenir(j).souvenir << endl;
                file2 << DB.at(i).getSouvenir(j).cost;
            }
            else
            {
            file2 << DB.at(i).getSouvenir(j).souvenir << endl;
            file2 << DB.at(i).getSouvenir(j).cost << endl;
            }
        }
    }

    file2.close();
    file3.open("inputDistances.txt");
    for(unsigned int i = 0; i < DB.size(); i++)
    {
        for(unsigned int j = 0; j < DB.size() - 1; j++)
        {
            file3 << DB.at(i).getDistances(j).endingCollege << endl;
            if(i == DB.size() - 1 && j == DB.size() - 2)
            file3 << DB.at(i).getDistances(j).distanceBetween;
            else
            file3 << DB.at(i).getDistances(j).distanceBetween << endl;
        }
    }

}
