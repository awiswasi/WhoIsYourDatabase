#include "customtrip.h"
#include "ui_customtrip.h"
#include "dataBase.h"
#include "tripplan.h"
#include "triptake.h"
#include <QDebug>
#include <QListWidgetItem>

//      /////////////
//    /////////////////
//   /////         /////
//  /////           /////
//  /////////////////////
//  /////////////////////
//  /////////////////////
//  /////////////////////
//  ////////    /////////
//  /////////   //////////

CustomTrip::CustomTrip(const std::vector<College> &database, const int PREV_HOME, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomTrip)
{
    char STARTING_FROM[] = "Starting from ";

    ui->setupUi(this);

    allColleges = database;
    displayColleges = database;

    startingCollege = PREV_HOME - 1;

    qDebug() << displayColleges[PREV_HOME - 1].getName().c_str();

    ui->label->setText(strcat(STARTING_FROM,displayColleges[PREV_HOME - 1].getName().c_str()));

    displayColleges.erase(displayColleges.begin() + PREV_HOME - 1);

    for (College college : displayColleges)
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(college.getName().c_str());
        item->setCheckState(Qt::Unchecked);

        ui->listView->addItem(item);
    }
}

//  ////////////
//  ///      /////
//  ///          /////
//  ///          /////
//  ///      /////
//  ///////////////
//  //////////////////
//  ///      /////
//  ///          /////
//  ///          /////
//  ///      /////
//  ////////////

std::vector<College> CustomTrip::sortColleges(int startingCollege, std::vector<College> collegesLeft, std::vector<College> collegesDone = {}, std::vector<int> doneIndexes = {})
{
    qDebug("Function called");

    int nextCollege = 0;
    double smallestNext = 999999999;
    bool found;
    int j;

    if(collegesDone.size() == collegesLeft.size() - removedCollegeCount)
    {
        for (College i : collegesDone)
        {
            qDebug() << i.getName().c_str();
        }

        return collegesDone;
    }
    else
    {
        collegesDone.push_back(collegesLeft[startingCollege]);
        doneIndexes.push_back(startingCollege);

        for(int i = 0; i < int(collegesLeft.size() - 1); i++)
        {
            if(smallestNext > collegesLeft[startingCollege].getDistances(i).distanceBetween)
            {
                found = false;
                j = 0;

                while(!found && j < int(collegesLeft.size()))
                {
                    if(collegesLeft[j].getName() == collegesLeft[startingCollege].getDistances(i).endingCollege)
                    {
                        found = true;
                        qDebug() << collegesLeft[startingCollege].getDistances(i).endingCollege.c_str();
                    }
                    else
                    {
                        j++;
                    }
                }

                if(!std::count(doneIndexes.begin(), doneIndexes.end(), j))
                {
                    smallestNext = collegesLeft[startingCollege].getDistances(i).distanceBetween;
                    qDebug() << "               MY ASSIGNMENT" << smallestNext;
                    if(collegesDone[collegesDone.size()-1].distanceTraveled > smallestNext && smallestNext != 0 || collegesDone[collegesDone.size()-1].distanceTraveled==0)
                        collegesDone[collegesDone.size()-1].distanceTraveled = smallestNext;
                    nextCollege = j;
                }
            }
        }
    }
    qDebug() << "                 CALLED HERE  " << smallestNext;
    return sortColleges(nextCollege,collegesLeft,collegesDone,doneIndexes);
}

CustomTrip::~CustomTrip()
{
    delete ui;
}

void CustomTrip::on_buttonBox_accepted()
{
    this->close();

    for (int i = 0; i < ui->listView->count(); i++)
    {
        if(ui->listView->item(i)->checkState() == Qt::Unchecked)
        {
            if(startingCollege > i)
                alreadyDoneColleges.push_back(i);
            else
                alreadyDoneColleges.push_back(i+1);
        }
    }

    removedCollegeCount = alreadyDoneColleges.size();

    TripTake triptake(sortColleges(startingCollege,allColleges,{},alreadyDoneColleges));
    triptake.exec();
}
