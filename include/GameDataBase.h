#ifndef GAMEDATABASE_H
#define GAMEDATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <vector>

#include "Game.h"

class GameDataBase
{
public:
    QSqlDatabase dataBase;

    QString demandName[5];
    void ModifyGame(int id,int com,int rand,int inter,int time,int players);
    void GetGames(std::vector<Game>resoult,int com,int rand,int inter,int time,int players);
    std::vector<Game*> GetAllGames();
    GameDataBase();
    virtual ~GameDataBase();
};

#endif // GAMEDATABASE_H
