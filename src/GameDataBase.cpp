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
    int demands[NUMBER_OF_DEMANDS] = { com, rand, inter, time, players};
    int demandCnt=0;
    bool whereSet=false;
    QSqlQuery query;
    QString command;
    command="SELECT game_name FROM games";
    for(int i=0;i<NUMBER_OF_DEMANDS-1;i++)
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
        propertiesStruct properties;
        properties.name=name;
        for(int i=0;i<6;i++)
        {
           properties.numericVal.push_back(params[i]);
        }
        Game* game=new Game(properties);
        result.push_back(game);

    }
    return result;
}


void GameDataBase::AddGame(int id,propertiesStruct data)
{
    qDebug()<<"add";
    QSqlQuery query;
    QString command;
    command=QString("INSERT INTO games VALUES(%1,\"%2\",%3,%4,%5,%6,%7,%8);")
            .arg(id).arg(data.name).arg(data.numericVal[0]).arg(data.numericVal[1])
            .arg(data.numericVal[2]).arg(data.numericVal[3]).arg(data.numericVal[4])
            .arg(data.numericVal[5]);
    qDebug()<<command;
    query.exec(command);
}


void GameDataBase::ModifyGame(QString name,int id,int com,int rand,int inter,int time,int min_pl,int max_pl)
{
    qDebug()<<"edit";
    QSqlQuery query;
    QString command;
    command=QString("UPDATE games SET game_name=\"%1\", complexity=%2 ,randomness=%3, interaction=%4, "
            "game_time=%5, min_players=%6, max_palyers=%7 WHERE game_id=%8;").arg(name).arg(com).arg(rand)
            .arg(inter).arg(time).arg(min_pl).arg(max_pl).arg(id);
    qDebug()<<command;
    query.exec(command);
}


GameDataBase::~GameDataBase()
{
    dataBase.close();
}
