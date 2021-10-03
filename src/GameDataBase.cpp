#include "GameDataBase.h"

GameDataBase::GameDataBase()
{
    dataBase = QSqlDatabase::addDatabase("QMYSQL");
    dataBase.setHostName("localhost");
    dataBase.setUserName("root");
    dataBase.setPassword("Patapon3");
    dataBase.setDatabaseName("boardgames");
    dataBase.setPort(3306);
    dataBase.open();


    demandName[0]="complexity";
    demandName[1]="randomness";
    demandName[2]="interaction";
    demandName[3]="game_time";
    demandName[4]="players";
}



void GameDataBase::GetGames(std::vector<Game>resoult,int com,int rand,int inter,int time,int players)
{
    int demands[5] = { com, rand, inter, time, players};
    int demandCnt=0;
    bool whereSet=false;
    QSqlQuery query;
    QString command;
    command="SELECT game_name FROM games";
    for(int i=0;i<4;i++)
    {
        if(demands[i]!=(-1))
        {
            if(!whereSet)
            {
                whereSet=true;
                command+=" WHERE";
            }
            if(demandCnt>0)
            {
                command+=" AND";
            }
            QString addon = QString(" %1=%2").arg(demandName[i]).arg(demands[i]);
            command+=addon;
            demandCnt++;
        }
    }
    if(demands[4]!=(-1))
    {
        if(demandCnt>0)
        {
            command+=" AND";
        }
        QString addon = QString(" min_players<%1 AND max_players>%1").arg(demands[4]);
        command+=addon;
    }
    query.exec(command);
    while(query.next())
    {
        QString name = query.value(0).toString();
    }
}


std::vector<Game*> GameDataBase::GetAllGames()
{
    QSqlQuery query;
    int params[6];
    std::vector<Game*> result;
    query.exec("SELECT * FROM games");
    while(query.next())
    {
        QString name = query.value(1).toString();
        for(int i=0;i<6;i++)
        {
            params[i] = query.value(i+2).toInt();
        }
        Game* game=new Game(name,params[0],params[1],params[2],params[3],params[4],params[5]);
        result.push_back(game);
    }
    return result;
}


void GameDataBase::ModifyGame(int id, int com, int rand, int inter, int time, int players)
{
    QSqlQuery query;
    QString command;
    command=QString("UPDATE games SET complexity=%1 ,randomness=%2, interaction=%3, "
            "game_time=%4 WHERE game_id=%5").arg(com).arg(rand).arg(inter).arg(time).arg(id);
    qDebug()<<command;
    query.exec(command);
}


GameDataBase::~GameDataBase()
{
    dataBase.close();
}
