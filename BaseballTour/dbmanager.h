#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QApplication>
#include <QtSql>
#include <QtDebug>
#include "stadiumstructs.h"
#include <QFileInfo>
#include <qarraydata.h>
#include <algorithm>
#include <QMap>
#include <functional>
#include <array>
#include <iostream>
#include <QVector>
#include <qvector.h>

/*!
   * \file dbmanager.h
   * \brief  Header for database wrapper class
   *
   * This file contains all of the declarations of the dbmanager class
   */




/*!
 * \brief The dbManager class
 *
 * Manages the sqlite data base that contians citys and their menu items
 */
class dbManager
{

public:

    /*!
     * \brief dbManager
     *
     * Constructor
     */
    dbManager();

    //Sorted by stadium order
    int getNumStadiums(QString name);

    //get all names for City
    /*!
     * \brief getCityNames
     *
     * Gets all city names and puts them in a QVector
     * \return QVector of city names
     */
    QVector<QString> getTeamNames();
    //utility methods to retrieve other attributes


    /*!
     * \brief getDistFrom
     *
     * Gets the specified citys distance from start city to endcity
     * \param startCity
     * \param endCity
     * \return city distances from start city to end city
     */
    int getDistfrom(QString startCity, QString endCity);


    /*!
     * \brief getRev
     *
     * Gets the total revenue for the specified city
     * \param CityName
     * \return total lifetime revenue of a city
     */
    QString getRev(QString CityName);


    /*!
     * \brief getNumItems
     *
     * Returns the number of menu items a city has
     * \param CityName
     * \return number of items on the menu
     */
    QString getNumItems(QString CityName);


    /*!
     * \brief getMenuItems: Returns the names of all menu items for a city
     * \param CityName
     * \return menu item names
     */
    QVector<QString> getCityItems(QString CityName);

    QVector<DistanceInfo> getGraphDistances();

    QVector<StadiumInfo> getStadiumInfo();

    /*!
     * \brief Exists: checks if a menu item exists
     * \param CityName
     * \param itemName
     * \return t/f if the item exists
     */
    bool Exists(QString CityName, QString itemName);


    /*!
     * \brief cityExists: checks if a city exists
     * \param CityName
     * \return t/f if the city exists
     */
    bool cityExists(QString CityName);


    /*!
     * \brief removeItem: Removes a menu item
     * \param CityName
     * \param itemName
     * \return t/f result of the operation
     */
    bool removeItem(QString CityName, QString itemName);


    /*!
     * \brief updateItem: Updates a menu item's price
     * \param CityName
     * \param itemName
     * \param price
     * \return t/f result of the operation
     */
    bool updateItem(QString CityName, QString itemName, double price);


    /*!
     * \brief addItem: Adds a new menu item
     * \param CityName
     * \param itemName
     * \return t/f result of the operation
     */
    bool addItem(QString CityName, QString itemName, double price);


    /*!
     * \brief addCity: Adds a new city
     * \param CityName
     * \param sadDist
     * \param distances
     * \return t/f result of the operation
     */
    bool addCity(QString CityName, double sadDist);


    /*!
     * \brief getCityName: Gets a city name based on id
     * \param id
     * \return city name
     */
    QString getCityName(int id);


    /*!
     * \brief updateDistances: Updates distances of previous citys when adding a new city
     * \param distances
     * \return t/f result of the operation
     */
    bool updateDistances(QVector<double> distances); //updates the previous Cityaurnts


    /*!
     * \brief distancesToString: Parses a QVector of doubles into a single string for storage in the database
     * \param distances
     * \return QString of distances
     */
    QString distancesToString(QVector<int> distances); //converts the distances to a string to store in the db


    /*!
     * \brief getDistances: Gets the distances to other citys for a city
     * \param CityName
     * \return distances in string form
     */
    QString getDistances(QString CityName);

    QVector<QString> getStadiumItems(QString teamName);

    QString getItemPrice(QString teamName, QString itemName);

    /*!
     * \brief updateTotRev: Accumulates the total revenue for a city
     * \param CityName
     * \param value
     * \return t/f result of the operation
     */
    bool updateTotRev(QString CityName, double value);

    /*!
     * \brief getDistances: Accumulates each city's distance to Berlin
     * \return t/f result of the operation
     */
    QVector<StadiumInfo> getInfo(QString teamName);
    bool updateInfo(int capacityChange, QString myString, QString teamName, int key);
    void tempDelete();
    bool addTeam(StadiumInfo myStadiumInfo, QVector<DistanceInfo>tempDistInfo);
    QVector<QString> getStadiums();
    QVector<StadiumInfo> sortedByCapacity();
    QVector<StadiumInfo> sortedChronologicalOrder();
    QVector<StadiumInfo> sortedStadiumTypology();
    QVector<StadiumInfo> sortedByTeamStadium(QString name);
    QVector<StadiumInfo> surfaceSorted();
    QVector<SouvenirInfoTemporary> getSouvenirInfo();                              //    <<------------------------------------
    void InsertSouvenir(const SouvenirInfoTemporary inSouvenir);
    void RemoveSouvenir(const SouvenirInfoTemporary inSouvenir);
    void ModifySouvenir(const SouvenirInfoTemporary initialSouvenir, const SouvenirInfoTemporary finalSouvenir);


    /*!
     * \brief citiesToTisit: Accumulates a queue of cities ordered by distance in ascending order
     * \param StartingCity
     * \return t/f result of the operation
     */
    QQueue<QString> citiesToTisit(QString StartingCity);


    /*!
     * \brief citiesToTisit: Accumulates a queue of cities ordered by distance in ascending order
     */
    void addCitiesFromDatabase();


    /*!
     * \brief AddDistance: Adds a distance between two given cities
     * \param StartingCity
     * \return t/f whether the distance was added
     */
    bool AddDistance(QString startCity, QString endCity,double newDist);
    QSqlDatabase db; //the database


private:


};

#endif // DBMANAGER_H



















//#ifndef DBMANAGER_H
//#define DBMANAGER_H

//#include <QApplication>
//#include <QtSql>
//#include <QtDebug>
//#include "stadiumstruct.h"
//#include <QFileInfo>
//#include <qarraydata.h>
//#include <algorithm>
//#include <functional>
//#include <array>
//#include <iostream>
//#include <QVector>
//#include <qvector.h>

///*!
//   * \file dbmanager.h
//   * \brief  Header for database wrapper class
//   *
//   * This file contains all of the declarations of the dbmanager class
//   */




///*!
// * \brief The dbManager class
// *
// * Manages the sqlite data base that contians citys and their menu items
// */
//class dbManager
//{

//public:

//    /*!
//     * \brief dbManager
//     *
//     * Constructor
//     */
//    dbManager();


//    //get all names for City
//    /*!
//     * \brief getCityNames
//     *
//     * Gets all city names and puts them in a QVector
//     * \return QVector of city names
//     */
//    QVector<QString> getTeamNames();
//    //utility methods to retrieve other attributes


//    /*!
//     * \brief getDistFrom
//     *
//     * Gets the specified citys distance from start city to endcity
//     * \param startCity
//     * \param endCity
//     * \return city distances from start city to end city
//     */
//    int getDistfrom(QString startCity, QString endCity);


//    /*!
//     * \brief getRev
//     *
//     * Gets the total revenue for the specified city
//     * \param CityName
//     * \return total lifetime revenue of a city
//     */
//    QString getRev(QString CityName);


//    /*!
//     * \brief getNumItems
//     *
//     * Returns the number of menu items a city has
//     * \param CityName
//     * \return number of items on the menu
//     */
//    QString getNumItems(QString CityName);


//    /*!
//     * \brief getItemPrice: Returns the price of a certain item
//     *
//     * Returns the price of a certain item
//     * \param CityName
//     * \param itemName
//     * \return item price
//     */
//    QString getItemPrice(QString CityName, QString itemName);


//    /*!
//     * \brief getMenuItems: Returns the names of all menu items for a city
//     * \param CityName
//     * \return menu item names
//     */
//    QVector<QString> getCityItems(QString CityName);


//    QVector<StadiumInfo> getStadiumInfo();

//    /*!
//     * \brief Exists: checks if a menu item exists
//     * \param CityName
//     * \param itemName
//     * \return t/f if the item exists
//     */
//    bool Exists(QString CityName, QString itemName);


//    /*!
//     * \brief cityExists: checks if a city exists
//     * \param CityName
//     * \return t/f if the city exists
//     */
//    bool cityExists(QString CityName);


//    /*!
//     * \brief removeItem: Removes a menu item
//     * \param CityName
//     * \param itemName
//     * \return t/f result of the operation
//     */
//    bool removeItem(QString CityName, QString itemName);


//    /*!
//     * \brief updateItem: Updates a menu item's price
//     * \param CityName
//     * \param itemName
//     * \param price
//     * \return t/f result of the operation
//     */
//    bool updateItem(QString CityName, QString itemName, double price);


//    /*!
//     * \brief addItem: Adds a new menu item
//     * \param CityName
//     * \param itemName
//     * \return t/f result of the operation
//     */
//    bool addItem(QString CityName, QString itemName, double price);


//    /*!
//     * \brief addCity: Adds a new city
//     * \param CityName
//     * \param sadDist
//     * \param distances
//     * \return t/f result of the operation
//     */
//    bool addCity(QString CityName, double sadDist);


//    /*!
//     * \brief getCityName: Gets a city name based on id
//     * \param id
//     * \return city name
//     */
//    QString getCityName(int id);


//    /*!
//     * \brief updateDistances: Updates distances of previous citys when adding a new city
//     * \param distances
//     * \return t/f result of the operation
//     */
//    bool updateDistances(QVector<double> distances); //updates the previous Cityaurnts


//    /*!
//     * \brief distancesToString: Parses a QVector of doubles into a single string for storage in the database
//     * \param distances
//     * \return QString of distances
//     */
//    QString distancesToString(QVector<int> distances); //converts the distances to a string to store in the db


//    /*!
//     * \brief getDistances: Gets the distances to other citys for a city
//     * \param CityName
//     * \return distances in string form
//     */
//    QString getDistances(QString CityName);


//    /*!
//     * \brief updateTotRev: Accumulates the total revenue for a city
//     * \param CityName
//     * \param value
//     * \return t/f result of the operation
//     */
//    bool updateTotRev(QString CityName, double value);

//    /*!
//     * \brief getDistances: Accumulates each city's distance to Berlin
//     * \return t/f result of the operation
//     */
//    QVector<QString> getStadiums();
//    QVector<StadiumInfo> sortedByCapacity();
//    QVector<StadiumInfo> sortedChronologicalOrder();
//    QVector<StadiumInfo> sortedStadiumTypology();
//    QVector<StadiumInfo> sortedByLeague(QString league);

//    /*!
//     * \brief citiesToTisit: Accumulates a queue of cities ordered by distance in ascending order
//     * \param StartingCity
//     * \return t/f result of the operation
//     */
//    QQueue<QString> citiesToTisit(QString StartingCity);


//    /*!
//     * \brief citiesToTisit: Accumulates a queue of cities ordered by distance in ascending order
//     */
//    void addCitiesFromDatabase();


//    /*!
//     * \brief AddDistance: Adds a distance between two given cities
//     * \param StartingCity
//     * \return t/f whether the distance was added
//     */
//    bool AddDistance(QString startCity, QString endCity,double newDist);
//    QSqlDatabase db; //the database


//private:


//};

//#endif // DBMANAGER_H
