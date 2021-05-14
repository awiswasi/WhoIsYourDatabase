//#include "tripplan.h"
//#include "triptake.h"
//#include "ui_tripplan.h"
//#include "customtrip.h"
//#include <QDebug>

//TripPlan::TripPlan(const std::vector<College> &database, const int PREV_HOME, QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::TripPlan),
//    plannedColleges(database)
//{
//    setWindowFlag(Qt::WindowContextHelpButtonHint,false);
//    ui->setupUi(this);

//    //set spinbox range
//    ui->spin_numColleges->QSpinBox::setMaximum(database.size());
//    ui->spin_numColleges->QSpinBox::setValue(database.size());

//    //populate dropdown list
//    ui->dropdown_CollegeList->addItem("Select a school...");
//    for(unsigned long long int i = 0; i < database.size(); i++)
//    {
//        ui->dropdown_CollegeList->addItem(QString::fromStdString(plannedColleges.at(i).getName()));
//    }

//    //populate second dropdown list
//    ui->dropdown_CollegeList_2->addItem("Select a school...");
//    for(unsigned long long int i = 0; i < database.size(); i++)
//    {
//        ui->dropdown_CollegeList_2->addItem(QString::fromStdString(plannedColleges.at(i).getName()));
//    }

//    ui->dropdown_CollegeList->setCurrentIndex(PREV_HOME);
//    ui->dropdown_CollegeList_2->setCurrentIndex(PREV_HOME);

//}

//TripPlan::~TripPlan()
//{
//    delete ui;
//}

//std::vector<College> TripPlan::sortColleges(int startingCollege, std::vector<College> collegesLeft, std::vector<College> collegesDone = {}, std::vector<int> doneIndexes = {})
//{
//    qDebug("Function called");

//    int nextCollege = 0;
//    double smallestNext = 999999999;
//    bool found;
//    int j;

//    if(collegesDone.size() == collegesLeft.size())
//    {
//        for (College i : collegesDone)
//        {
//            qDebug() << i.getName().c_str();
//        }

//        return collegesDone;
//    }
//    else
//    {
//        collegesDone.push_back(collegesLeft[startingCollege]);
//        doneIndexes.push_back(startingCollege);

//        for(int i = 0; i < int(collegesLeft.size() - 1); i++)
//        {
//            if(smallestNext > collegesLeft[startingCollege].getDistances(i).distanceBetween)
//            {
//                found = false;
//                j = 0;

//                while(!found && j < int(collegesLeft.size()))
//                {
//                    if(collegesLeft[j].getName() == collegesLeft[startingCollege].getDistances(i).endingCollege)
//                    {
//                        found = true;
//                        qDebug() << collegesLeft[startingCollege].getDistances(i).endingCollege.c_str();
//                    }
//                    else
//                    {
//                        j++;
//                    }
//                }

//                if(!std::count(doneIndexes.begin(), doneIndexes.end(), j))
//                {
//                    smallestNext = collegesLeft[startingCollege].getDistances(i).distanceBetween;
//                    qDebug() << "               MY ASSIGNMENT" << smallestNext;
//                    if(collegesDone[collegesDone.size()-1].distanceTraveled > smallestNext && smallestNext != 0 || collegesDone[collegesDone.size()-1].distanceTraveled==0)
//                        collegesDone[collegesDone.size()-1].distanceTraveled = smallestNext;
//                    nextCollege = j;
//                }
//            }
//        }
//    }
//    qDebug() << "                 CALLED HERE  " << smallestNext;
//    return sortColleges(nextCollege,collegesLeft,collegesDone,doneIndexes);
//}

//std::vector<College> TripPlan::findRoute(int numColleges)
//{
//    vector<College> returnVec = sortColleges(ui->dropdown_CollegeList->currentIndex() - 1, plannedColleges);

//    while(int(returnVec.size()) > numColleges)
//    {
//        returnVec.pop_back();
//    }

//    return returnVec;
//}

//void TripPlan::on_takeTripButton_clicked()
//{
//    this->close();
////    qDebug() << plannedColleges[ui->dropdown_CollegeList->currentIndex() - 1].getName().c_str();
//    TripTake triptake(plannedColleges);
//    triptake.exec();
//}


//void TripPlan::on_button_AutomaticTrip_clicked()
//{
//    if(ui->dropdown_CollegeList->currentIndex() == 0)
//        return;

//    this->close();

//    for (College i : plannedColleges)
//    {
//        qDebug() << i.getName().c_str();
//    }

//    TripTake triptake(findRoute(ui->spin_numColleges->value()));
//    triptake.exec();
//}


//void TripPlan::on_button_CustomTrip_clicked()
//{
//    this->close();
//    if(ui->dropdown_CollegeList_2->currentIndex() == 0)
//        return;

//    CustomTrip customtrip(plannedColleges,ui->dropdown_CollegeList_2->currentIndex());
//    customtrip.exec();
//}
