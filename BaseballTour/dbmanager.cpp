#include "dbmanager.h"
#include <qdebug.h>
/*!
   * \file dbmanager.cpp
   * \brief  Source file for dbmanager database wrapper class methods
   *
   * This file contains all of the definitions of the dbmanager database wrapper class
   */


dbManager::dbManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Project2database.db");
//    db.open();
    if(!db.open())
        qDebug() << "Not connected to DB.";
    else if(db.open())
        qDebug() << "Connected to DB.";
}

//Get stadium info without any order
QVector<StadiumInfo> dbManager:: getStadiumInfo()
{
    QSqlQuery query(db);
    QVector<StadiumInfo> infoVector;
    StadiumInfo myStructInfo;
    QString format = "MMMM d, yyyy"; //Format for QT DATE TIME CLASS
    QDateTime dateTime1;

    //select in the order they are given
    query.prepare("SELECT * FROM MLB");

    if(query.exec())
    {
        while(query.next()) //these seem to be coming out in alphabetical order by default
        {
            myStructInfo.stadiumName = query.value(0).toString();
            myStructInfo.teamName = query.value(1).toString();
            myStructInfo.address = query.value(2).toString();
            myStructInfo.capacity = query.value(3).toInt();
            myStructInfo.phoneNumber = query.value(4).toString();
            myStructInfo.surface = query.value(5).toString();
            dateTime1 = QDateTime::fromString(query.value(6).toString(), format);
            myStructInfo.dateOpen = dateTime1;
            myStructInfo.leagueType = query.value(7).toString();
            myStructInfo.typology = query.value(8).toString();
            infoVector.push_back(myStructInfo);
        }
    }
    else
    {
       qDebug() << query.lastError().text();
    }
    return infoVector;
}

//Sorted by capacity order
QVector<StadiumInfo> dbManager:: sortedByCapacity()
{
    QSqlQuery query(db);
    QVector<StadiumInfo> capacityVector;
    StadiumInfo myStructInfo;
    QString format = "MMMM d, yyyy"; //Format for QT DATE TIME CLASS
    QDateTime dateTime1;

    //select in the order they are given
    query.prepare("SELECT * FROM MLB ORDER BY Capacity ASC;");

    if(query.exec())
    {
//        qDebug() << "made it here\n";

        while(query.next()) //these seem to be coming out in alphabetical order by default
        {
            myStructInfo.stadiumName = query.value(0).toString();
            myStructInfo.teamName = query.value(1).toString();
            myStructInfo.address = query.value(2).toString();
            myStructInfo.capacity = query.value(3).toInt();
            myStructInfo.phoneNumber = query.value(4).toString();
            myStructInfo.surface = query.value(5).toString();
            dateTime1 = QDateTime::fromString(query.value(6).toString(), format);
            myStructInfo.dateOpen = dateTime1;
            myStructInfo.leagueType = query.value(7).toString();
            myStructInfo.typology = query.value(8).toString();
            capacityVector.push_back(myStructInfo);
        }
    }
    else
    {
       qDebug() << query.lastError().text();
    }
    return capacityVector;
}

int dbManager::getNumStadiums(QString name)
{
    QSqlQuery query(db);
    QVector<StadiumInfo> sortVector;
    StadiumInfo myStructInfo;
    QString format = "MMMM d, yyyy"; //Format for QT DATE TIME CLASS
    QDateTime dateTime1;

    int count = 0;

    if(name == "Team")
    {
        //select in the order they are given
        query.prepare("SELECT * FROM MLB ORDER BY Team ASC;");
    }
    else
    {
        //select in the order they are given
        query.prepare("SELECT * FROM MLB ORDER BY Stadium ASC;");
    }

        if(query.exec())
        {
//            qDebug() << "made it here 2\n";

            while(query.next()) //these seem to be coming out in alphabetical order by default
            {
                count++;
            }
        }
        else
        {
           qDebug() << query.lastError().text();
        }
        return count;
}

//Sorted by stadium order
QVector<StadiumInfo> dbManager:: sortedByTeamStadium(QString name)
{
    QSqlQuery query(db);
    QVector<StadiumInfo> sortVector;
    StadiumInfo myStructInfo;
    QString format = "MMMM d, yyyy"; //Format for QT DATE TIME CLASS
    QDateTime dateTime1;

    if(name == "Team")
    {
        //select in the order they are given
        query.prepare("SELECT * FROM MLB ORDER BY Team ASC;");
    }
    else
    {
        //select in the order they are given
        query.prepare("SELECT * FROM MLB ORDER BY Stadium ASC;");
    }

        if(query.exec())
        {
//            qDebug() << "made it here 2\n";

            while(query.next()) //these seem to be coming out in alphabetical order by default
            {
                myStructInfo.stadiumName = query.value(0).toString();
                myStructInfo.teamName = query.value(1).toString();
                myStructInfo.address = query.value(2).toString();
                myStructInfo.capacity = query.value(3).toInt();
                myStructInfo.phoneNumber = query.value(4).toString();
                myStructInfo.surface = query.value(5).toString();
                dateTime1 = QDateTime::fromString(query.value(6).toString(), format);
                myStructInfo.dateOpen = dateTime1;
                myStructInfo.leagueType = query.value(7).toString();
                myStructInfo.typology = query.value(8).toString();
                sortVector.push_back(myStructInfo);
            }
        }
        else
        {
           qDebug() << query.lastError().text();
        }
        return sortVector;
}

//Sort for typology order
QVector<StadiumInfo> dbManager:: sortedStadiumTypology()
{
    QSqlQuery query(db);
    QVector<StadiumInfo> typologyVector;
    StadiumInfo myStructInfo;
    QString format = "MMMM d, yyyy"; //Format for QT DATE TIME CLASS
    QDateTime dateTime1;

    //select in the order they are given
    query.prepare("SELECT * FROM MLB ORDER BY Typology ASC");

    if(query.exec())
    {
//        qDebug() << "made it here\n";

        while(query.next()) //these seem to be coming out in alphabetical order by default
        {
            myStructInfo.stadiumName = query.value(0).toString();
            myStructInfo.teamName = query.value(1).toString();
            myStructInfo.address = query.value(2).toString();
            myStructInfo.capacity = query.value(3).toInt();
            myStructInfo.phoneNumber = query.value(4).toString();
            myStructInfo.surface = query.value(5).toString();
            dateTime1 = QDateTime::fromString(query.value(6).toString(), format);
            myStructInfo.dateOpen = dateTime1;
            myStructInfo.leagueType = query.value(7).toString();
            myStructInfo.typology = query.value(8).toString();
            typologyVector.push_back(myStructInfo);
        }
    }
    else
    {
       qDebug() << query.lastError().text();
    }
    return typologyVector;
}

//Sorted by surface order
QVector<StadiumInfo> dbManager:: surfaceSorted()
{
    QSqlQuery query(db);
    QVector<StadiumInfo> surfaceVector;
    QString name = "Grass";
    StadiumInfo myStructInfo;
    QString format = "MMMM d, yyyy"; //Format for QT DATE TIME CLASS
    QDateTime dateTime1;

    //select in the order they are given
    //squery.prepare("SELECT * FROM MLB ORDER BY Surface ASC");
    query.prepare("SELECT * FROM MLB where Surface = '" +name+"' ORDER by Team ASC;");

    if(query.exec())
    {
//        qDebug() << "made it here\n";

        while(query.next()) //these seem to be coming out in alphabetical order by default
        {
            myStructInfo.stadiumName = query.value(0).toString();
            myStructInfo.teamName = query.value(1).toString();
            myStructInfo.address = query.value(2).toString();
            myStructInfo.capacity = query.value(3).toInt();
            myStructInfo.phoneNumber = query.value(4).toString();
            myStructInfo.surface = query.value(5).toString();
            dateTime1 = QDateTime::fromString(query.value(6).toString(), format);
            myStructInfo.dateOpen = dateTime1;
            myStructInfo.leagueType = query.value(7).toString();
            myStructInfo.typology = query.value(8).toString();
            surfaceVector.push_back(myStructInfo);
        }
    }
    else
    {
       qDebug() << query.lastError().text();
    }
    return surfaceVector;
}

//Sorted by chronological order
QVector<StadiumInfo> dbManager:: sortedChronologicalOrder()
{
    QSqlQuery query(db);
    int j;
    StadiumInfo temp;
    QVector<StadiumInfo> chronologicalVector;
    StadiumInfo myStructInfo;
    QString format = "MMMM d, yyyy"; //Format for QT DATE TIME CLASS
    QDateTime dateTime1;

    //select in the order they are given
    query.prepare("SELECT * FROM MLB");
    if(query.exec())
    {
//        qDebug() << "made it here\n";
        while(query.next()) //these seem to be coming out in alphabetical order by default
        {
            myStructInfo.stadiumName = query.value(0).toString();
            myStructInfo.teamName = query.value(1).toString();
            myStructInfo.address = query.value(2).toString();
            myStructInfo.capacity = query.value(3).toInt();
            myStructInfo.phoneNumber = query.value(4).toString();
            myStructInfo.surface = query.value(5).toString();
            dateTime1 = QDateTime::fromString(query.value(6).toString(), format);
            myStructInfo.dateOpen = dateTime1;
            myStructInfo.leagueType = query.value(7).toString();
            myStructInfo.typology = query.value(8).toString();
            chronologicalVector.push_back(myStructInfo);
        }
    }
    else
    {
       qDebug() << query.lastError().text();
    }

        //Simple insertion sort to sort the vector in chronological order
        for (int i = 0; i < chronologicalVector.size(); i++)
        {
            j = i;

            while (j > 0 && chronologicalVector[j].dateOpen < chronologicalVector[j-1].dateOpen){
                  temp = chronologicalVector[j];
                  chronologicalVector[j] = chronologicalVector[j-1];
                  chronologicalVector[j-1] = temp;
                  j--;
                  }
        }


    return chronologicalVector;
}

QVector<DistanceInfo> dbManager::getGraphDistances()
{
    QSqlQuery query(db);
    QVector<DistanceInfo> graphInfo;
    DistanceInfo temp;
    query.prepare("SELECT * FROM Distances ORDER BY Start ASC");

    if(query.exec())
    {

        while(query.next())
        {
            temp.startStad = query.value(0).toString();
            temp.endStad = query.value(1).toString();
            temp.distance= query.value(2).toInt();

            graphInfo.push_back(temp);
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    return graphInfo;
}

////Function used to get all information from souvenirs && store into a temp vector                   //  <<--------------------------------------
QVector<SouvenirInfoTemporary> dbManager::getSouvenirInfo()
{
    QSqlQuery query(db);
    int j;
    SouvenirInfoTemporary myStructInfo;
    QVector<SouvenirInfoTemporary> souvenirVector;

    //select in the order they are given
    query.prepare("SELECT * FROM Souvenirs ORDER BY Team ASC");
    if(query.exec())
    {
//        qDebug() << "made it here\n";
        while(query.next()) //these seem to be coming out in alphabetical order by default
        {
            myStructInfo.teamName1 = query.value(0).toString();
            myStructInfo.itemName1 = query.value(1).toString();
            myStructInfo.price1 = query.value(2).toDouble();
            souvenirVector.push_back(myStructInfo);
        }
    }
    else
    {
       qDebug() << query.lastError().text();
    }


    return souvenirVector;
}

//Only get team names
QVector<QString> dbManager:: getTeamNames()
{
    QSqlQuery query(db);
    QVector<QString> names;

    //select in the order they are given
    query.prepare("SELECT Team FROM MLB ORDER BY Team ASC;");

    if(query.exec())
    {
//        qDebug() << "made it here\n";

        while(query.next()) //these seem to be coming out in alphabetical order by default
        {
            QString name = query.value(0).toString();
            names.push_front(name);
        }
    }
    else
    {
       qDebug() << query.lastError().text();
    }
    return names;
}

QVector<QString> dbManager::getStadiums()
{
    QSqlQuery query(db);
    QVector<QString> stadiums;

    query.prepare("SELECT Stadium FROM MLB ORDER BY Team");

    if(query.exec())
    {
        while(query.next())
        {
            QString stadium = query.value(0).toString();
            stadiums.push_front(stadium);
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    return stadiums;
}

void dbManager::InsertSouvenir(const SouvenirInfoTemporary inSouvenir)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO Souvenirs(Team, Souvenir, Price) VALUES ('" +inSouvenir.teamName1+ "', '" +inSouvenir.itemName1+ "', '" +QString::number(inSouvenir.price1)+ "')");

    if(!query.exec())
//    {
//        qDebug() << "SUCCESS ADDING SOUVENIR";
//    }
//    else
    {
        qDebug() << query.lastError().text() << "UNABLE TO INSERT SOUVENIR";
    }

}

void dbManager::RemoveSouvenir(const SouvenirInfoTemporary inSouvenir)
{
    QSqlQuery query(db);

    query.prepare("DELETE FROM Souvenirs WHERE Team = ('" +inSouvenir.teamName1+ "') AND Souvenir = ('" +inSouvenir.itemName1+ "')");

    if(!query.exec())
//    {
//        qDebug() << "SUCCESS REMOVING SOUVENIR";
//    }
//    else
    {
        qDebug() << query.lastError().text() << "UNABLE TO REMOVE SOUVENIR";
    }
}

void dbManager::ModifySouvenir(const SouvenirInfoTemporary initialSouvenir,
                               const SouvenirInfoTemporary finalSouvenir)
{
    QSqlQuery query(db);

//    qDebug() << "initial";
//    qDebug() << initialSouvenir.teamName1 << initialSouvenir.itemName1 << initialSouvenir.price1;
//    qDebug() << endl << finalSouvenir.teamName1 << finalSouvenir.itemName1 << finalSouvenir.price1;

    query.prepare("UPDATE Souvenirs SET Souvenir = ('" +finalSouvenir.itemName1+ "'),"
                                      " Price = ('" +QString::number(finalSouvenir.price1)+ "') "
                                      " WHERE Team= ('" +initialSouvenir.teamName1+ "') "
                                      " AND Souvenir = ('" +initialSouvenir.itemName1+ "') "
                                      " AND Price = ('" +QString::number(initialSouvenir.price1)+ "')");

    if(!query.exec())
//    {
//        qDebug() << "SUCCESS MODIFYING SOUVENIR";
//    }
//    else
    {
        qDebug() << query.lastError().text() << "UNABLE TO MODIFY SOUVENIR";
    }
}


QVector<QString> dbManager::getStadiumItems(QString teamName)
{
    QSqlQuery query(db);
    QVector<QString> names;

    query.prepare("SELECT Souvenir FROM Souvenirs WHERE Team = (:teamName)");

    query.bindValue(":teamName", teamName );

    if(query.exec())
    {
//        qDebug() << "Getting items";
        while(query.next()) //these seem to be coming out in alphabetical order by default
        {
            QString souv = {query.value(0).toString()};

            names.push_back(souv);
        }
    }
    else
    {
        qDebug() << query.lastError();
    }

    return names;

}

QString dbManager::getItemPrice(QString teamName, QString itemName)
{
    QSqlQuery query(db);

    query.prepare("SELECT Price FROM Souvenirs WHERE Team = (:teamName) AND Souvenir = (:itemName)");
    query.bindValue(":teamName", teamName);
    query.bindValue(":itemName", itemName);

    if(query.exec())
    {
        if(query.next())
        {
            double price =  query.value(0).toDouble();

            return QString::number(price, 'f', 2);
        }
    }
    else
    {
        qDebug() << query.lastError();
    }
    return "price" ;
}

void dbManager::tempDelete()
{
    QSqlQuery query2(db);
    QSqlQuery query3(db);

    query2.prepare("DELETE FROM mlb where Stadium = 'Las Vegas Stadium'");
    if(!query2.exec())
//    {
//        qDebug() << "Executed query #3" << endl;
//    }
//    else
    {
        qDebug() << "Could not execute query #3" << endl;
    }

    query2.prepare("Delete from Distances where Start = 'Las Vegas Stadium'");
    if(!query2.exec())
//    {
//        qDebug() << "Executed query #3" << endl;
//    }
//    else
    {
        qDebug() << "Could not execute query #3" << endl;
    }

    query2.prepare("Delete from Distances where [Ending Stadium] = 'Las Vegas Stadium'");
    if(!query2.exec())
//    {
//        qDebug() << "Executed query #3" << endl;
//    }
//    else
    {
        qDebug() << "Could not execute query #3" << endl;
    }

    query3.prepare("Delete from Souvenirs where Team = 'Las Vegas Gamblers'");

    if(query3.exec())
    {

    }
    else
    {
        qDebug() << "Could not execute query" << flush;
    }
}


bool dbManager::addTeam(StadiumInfo myStadiumInfo, QVector<DistanceInfo>tempDistInfo)

{
    QString format = "MMMM d, yyyy";

    QSqlQuery query(db);

    QSqlQuery query2(db);



    //Insert the stadium information

    query.prepare("Insert into mlb(Stadium, Team, Address, Capacity, [Phone Number], Surface, [Date Opened], [League Type], Typology) values ('"

                   +myStadiumInfo.stadiumName+ "', '" +myStadiumInfo.teamName+ "', '" +myStadiumInfo.address+ "', '" +QString::number(myStadiumInfo.capacity)+ "', '"

                   +myStadiumInfo.phoneNumber+ "', '" +myStadiumInfo.surface+ "', '" +myStadiumInfo.dateOpen.toString(format)+ "', '" +myStadiumInfo.leagueType+ "', '"

                   +myStadiumInfo.typology+ "')");

    bool isTrue = true;



    //Check if the query works

    if(query.exec())

    {

//        qDebug() << "Executed query #1" << endl;

        isTrue = true;

    }

    else

    {

        qDebug() << "Could not execute query #1" << endl;

        isTrue = false;

    }



    //Insert into distances all distances from the new stadium

    int index = 0;

    while(index < tempDistInfo.size())

    {

        query2.prepare("insert into Distances ([Start], [Ending Stadium], Distance) values ('"

                       +tempDistInfo[index].startStad+ "', '" +tempDistInfo[index].endStad+ "', '" +QString::number(tempDistInfo[index].distance)+ "')");

        if(query2.exec())

        {

            isTrue = true;

        }

        else

        {

            qDebug() << "Could not execute query #2" << endl;

            isTrue = false;

        }



        query2.prepare("insert into Distances ([Start], [Ending Stadium], Distance) values ('"

                   +tempDistInfo[index].endStad+ "', '" +tempDistInfo[index].startStad+ "', '" +QString::number(tempDistInfo[index].distance)+ "')");

        if(query2.exec())

        {

            isTrue = true;

        }

        else

        {

            qDebug() << "Could not execute query #2" << endl;

            isTrue = false;

        }

    index++;

}

    QSqlQuery query3 (db);
    //Replace vars with price, souvenir, team

    //Do this for each souvenir
    query3.prepare("Insert into Souvenirs (Team, Souvenir, Price) VALUES ('Las Vegas Gamblers', 'Baseball cap', 26.99)");

    if(query3.exec())
    {

    }
    else
    {
    qDebug() << "Error, could not execute" << flush;
    isTrue = false;
    }

                //Do this for each souvenir
   query3.prepare("Insert into Souvenirs (Team, Souvenir, Price) VALUES ('Las Vegas Gamblers', 'Baseball bat', 49.39)");

    if(query3.exec())
    {

    }
    else
    {
        qDebug() << "Error, could not execute" << flush;
        isTrue = false;
    }

                    //Do this for each souvenir
        query3.prepare("Insert into Souvenirs (Team, Souvenir, Price) VALUES ('Las Vegas Gamblers', 'Team pennant', 11.99)");

        if(query3.exec())
        {

        }
        else
        {
            qDebug() << "Error, could not execute" << flush;
            isTrue = false;
        }

                        //Do this for each souvenir
            query3.prepare("Insert into Souvenirs (Team, Souvenir, Price) VALUES ('Las Vegas Gamblers', 'Autographed baseball', 29.99)");

            if(query3.exec())
            {

            }
            else
            {
                qDebug() << "Error, could not execute" << flush;
                isTrue = false;
            }

             //Do this for each souvenir
            query3.prepare("Insert into Souvenirs (Team, Souvenir, Price) VALUES ('Las Vegas Gamblers', 'Team Jersey', 88.99)");

                if(query3.exec())
                {

                }
                else
                {
                    qDebug() << "Error, could not execute" << flush;
                    isTrue = false;
                }


    return isTrue;

}

QVector<StadiumInfo> dbManager::getInfo(QString teamName)
{
   QVector<StadiumInfo> myVector;
   StadiumInfo myStructInfo;
   QSqlQuery query(db);
   QString format = "MMMM d, yyyy"; //Format for QT DATE TIME CLASS
   QDateTime dateTime1;

   query.prepare("SELECT * FROM mlb where Team = ('"
                 +teamName+ "')");
   if(query.exec())
   {
       if(query.next())
       {
           myStructInfo.stadiumName = query.value(0).toString();
           myStructInfo.teamName = query.value(1).toString();
           myStructInfo.address = query.value(2).toString();
           myStructInfo.capacity = query.value(3).toInt();
           myStructInfo.phoneNumber = query.value(4).toString();
           myStructInfo.surface = query.value(5).toString();
           dateTime1 = QDateTime::fromString(query.value(6).toString(), format);
           myStructInfo.dateOpen = dateTime1;
           myStructInfo.leagueType = query.value(7).toString();
           myStructInfo.typology = query.value(8).toString();
           myVector.push_back(myStructInfo);
       }
       else
       {
           qDebug() << "Did not work 2";
       }
   }
   else
   {
       qDebug() << "Did not work!!!";
   }

   return myVector;

}

bool dbManager::updateInfo(int capacityChange,QString myString, QString teamName, int key)
{
    QSqlQuery query(db);
    bool success = false;

    //Update stadium name
    if(key == 1)
    {
        query.prepare("UPDATE MLB set Stadium = ('"

                      +myString+ "') WHERE team = ('"

                      +teamName+ "')");

        if(query.exec())
        {
//            qDebug() << "Worked!" << flush;
            success = true;
        }
        else
        {
//            qDebug() << teamName << " " << myString;
            success = false;
        }

        query.prepare("UPDATE Distances set Start = ('"

                      +myString+ "') WHERE Start = ('"

                      +myString+ "')");

        if(query.exec())
        {
//            qDebug() << "Worked!" << flush;
            success = true;
        }
        else
        {
            success = false;
//            qDebug() << teamName << " " << myString;
        }

        query.prepare("UPDATE Distances set [Ending Stadium] = ('"

                      +myString+ "') WHERE [Ending Stadium] = ('"

                      +myString+ "')");

        if(query.exec())
        {
//            qDebug() << "Worked!" << flush;
            success = true;
        }
        else
        {
            success = false;
//            qDebug() << teamName << " " << myString;
        }
    }
    //Update capacity
    else if(key == 2)
    {
        query.prepare("UPDATE MLB set Capacity = ('"

                      +QString::number(capacityChange)+ "') WHERE team = ('"

                      +teamName+ "')");

        if(query.exec())
        {
            success = true;
        }
        else
        {
            success = false;
        }
    }
    //Update date opened
    else if(key == 3)
    {
        query.prepare("UPDATE MLB set [Date Opened] = ('"

                      +myString+ "') WHERE team = ('"

                      +teamName+ "')");

        if(query.exec())
        {
            success = true;
        }
        else
        {
            success = false;
        }
    }
    //Update typology
    else if(key == 4)
    {
        query.prepare("UPDATE MLB set Typology = ('"

                      +myString+ "') WHERE team = ('"

                      +teamName+ "')");

        if(query.exec())
        {
            success = true;
        }
        else
        {
            success = false;
        }
    }
    //Update league type
    else if(key == 5)
    {
        query.prepare("UPDATE MLB set [League Type] = ('"

                      +myString+ "') WHERE team = ('"

                      +teamName+ "')");

        if(query.exec())
        {
            success = true;
        }
        else
        {
            success = false;
        }
    }
    //Update address
    else if(key == 6)
    {
        query.prepare("UPDATE MLB set Address = ('"

                      +myString+ "') WHERE team = ('"

                      +teamName+ "')");

        if(query.exec())
        {
            success = true;
        }
        else
        {
            success = false;
        }
    }
    //Update phone number
    else if(key == 7)
    {
        query.prepare("UPDATE MLB set [Phone Number] = ('"

                      +myString+ "') WHERE team = ('"

                      +teamName+ "')");

        if(query.exec())
        {
            success = true;
        }
        else
        {
            success = false;
        }
    }
    //Update Surface info
    else if(key == 8)
    {
        query.prepare("UPDATE MLB set Surface = ('"
                      +myString+ "') WHERE team = ('"
                      +teamName+ "')");

        if(query.exec())
        {
            success = true;
        }
        else
        {
            success = false;
        }
    }
    else
    {
        qDebug() << "How did it get here? \n\n";
    }
    return success;
}
