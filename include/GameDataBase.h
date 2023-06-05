#ifndef GAMEDATABASE_H
#define GAMEDATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <vector>

#include "PropertiesStruct.h"
#include "Game.h"
#include "Tags.h"

constexpr int NUMBER_OF_DEMANDS = 5;
struct loginCredentials;

class GameDataBase : public QObject
{
    Q_OBJECT
public:

    GameDataBase();
    GameDataBase(const GameDataBase& other);
    ~GameDataBase();

    void AddGame(int id,propertiesStruct data);
    void ModifyGame(int id,propertiesStruct data);
    void GetGames(std::vector<Game>resoult,int com,int rand,int inter,int time,int players);    
    void ShowLoginDialog();
    std::vector<Game*> GetAllGames();
    bool GetIsConnected() const;

signals:
    void loginSucces();
    void loginFailed(QString errorMessage);

private slots:
    void LoginToDB(const loginCredentials&  loginCredentials);

private:

    QString m_demandName[NUMBER_OF_DEMANDS] = {"complexity","randomness","interaction","game_time","players"};
    bool m_isConnected = false;
    QSqlDatabase m_dataBase;
};

#endif // GAMEDATABASE_H
