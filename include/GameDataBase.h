#ifndef GAMEDATABASE_H
#define GAMEDATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <vector>

#include "Game.h"

constexpr int NUMBER_OF_DEMANDS = 5;

class GameDataBase
{
public:
    QSqlDatabase dataBase;

    QString demandName[NUMBER_OF_DEMANDS];
    void ModifyGame(int id,int com,int rand,int inter,int time,int min_pl,int max_pl);
    void GetGames(std::vector<Game>resoult,int com,int rand,int inter,int time,int players);
    std::vector<Game*> GetAllGames();
    GameDataBase();
    virtual ~GameDataBase();
};

#endif // GAMEDATABASE_H
