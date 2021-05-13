#ifndef STADIUMSTRUCTS_H
#define STADIUMSTRUCTS_H
#include <QString>
#include <QDateTime>

struct StadiumInfo
{
    QString   teamName;
    QString   stadiumName;
    int       capacity;
    QString   location;
    QString   surface;
    QString   leagueType;
    QDateTime dateOpen;
    int       distanceToCenter;
    QString   typology;
    QString   roofType;


};


struct SouvenirInfoTemporary
{
    QString teamName1;
    QString itemName1;
    double price1;
};

struct SouvenirInfo
{
    QString itemName;
    double price;
};

struct DistanceInfo
{
    QString startStad;
    QString endStad;
    int distance;
};

struct TeamSouvenirs
{
    QString teamName;
    QVector<SouvenirInfo> mySouvenirs;
};



typedef QMap<QString, TeamSouvenirs> SouvenirMap;
typedef QPair<QString, TeamSouvenirs> SouvenirTeamPair;
#endif // STADIUMSTRUCTS_H
