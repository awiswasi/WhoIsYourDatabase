#ifndef STADIUMSTRUCTS_H
#define STADIUMSTRUCTS_H
#include <QString>
#include <QDateTime>

struct StadiumInfo
{
    QString    teamName;
    QString    stadiumName;
    int        capacity;
    QString    typology;
    QString    surface;
    int        dateOpen;
    QString    leagueType;
    QString    roofType;
    int        distanceToCenter;
    QString    location;
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
