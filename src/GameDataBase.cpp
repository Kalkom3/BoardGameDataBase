#include "GameDataBase.h"
#include "LoginView.h"

GameDataBase::GameDataBase()
{
    m_dataBase = QSqlDatabase::addDatabase("QMYSQL");
//    m_dataBase.setHostName("localhost");
//    m_dataBase.setUserName("root");
//    m_dataBase.setPassword("Patapon3");
//    m_dataBase.setm_dataBaseName("boardgamesdb");
//    m_dataBase.setPort(3306);
//    m_dataBase.open();


}

GameDataBase::GameDataBase(const GameDataBase& other)
{
    m_dataBase = QSqlDatabase::addDatabase("QMYSQL");
    m_isConnected = other.GetIsConnected();

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
            QString addon = QString(" %1=%2").arg(m_demandName[i]).arg(demands[i]);
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
}

void GameDataBase::LoginToDB(const loginCredentials& loginCredentials)
{

    m_dataBase.setHostName(loginCredentials.hostname);
    m_dataBase.setUserName(loginCredentials.username);
    m_dataBase.setPassword(loginCredentials.password);
    m_dataBase.setDatabaseName(loginCredentials.databaseName);
    m_dataBase.setPort(loginCredentials.port);

    if(m_dataBase.open())
    {
        m_isConnected=true;
        emit loginSucces();
    }
    else
    {
        emit loginFailed(m_dataBase.lastError().text());
    }
}

void GameDataBase::ShowLoginDialog()
{
    LoginView loginView;
    connect(&loginView,&LoginView::tryLogin,this,&GameDataBase::LoginToDB);
    connect(this, &GameDataBase::loginSucces, &loginView, &LoginView::onLoginSucces);
    connect(this, &GameDataBase::loginFailed, &loginView, &LoginView::onLoginFailed);
    loginView.exec();
}


std::vector<Game*> GameDataBase::GetAllGames()
{
    QSqlQuery query;
    int params[6];
    std::vector<bool>tempTags;
    std::vector<Game*> result;
    query.exec("SELECT * FROM games");
    while(query.next())
    {
        QString name = query.value(1).toString();
        for(int i=0;i<6;i++)
        {
            params[i] = query.value(i+2).toInt();
        }
        uint32_t sqlTags=query.value(8).toUInt();
        for(int i=0;i<NUMBER_OF_TAGS;i++)
        {
            tempTags.push_back(((sqlTags>>i)&1));
        }
        propertiesStruct properties;
        properties.name=name;
        properties.tags=tempTags;
        tempTags.clear();
        for(int i=0;i<6;i++)
        {
           properties.numericVal.push_back(params[i]);
        }
        Game* game=new Game(properties);
        result.push_back(game);

    }
    return result;
}

bool GameDataBase::GetIsConnected() const
{
    return m_isConnected;
}


void GameDataBase::AddGame(int id,propertiesStruct data)
{
    QSqlQuery query;
    QString command;
    command=QString("INSERT INTO games VALUES(%1,\"%2\",%3,%4,%5,%6,%7,%8);")
            .arg(id).arg(data.name).arg(data.numericVal[0]).arg(data.numericVal[1])
            .arg(data.numericVal[2]).arg(data.numericVal[3]).arg(data.numericVal[4])
            .arg(data.numericVal[5]);
    qDebug()<<command;
    query.exec(command);
}


void GameDataBase::ModifyGame(int id,propertiesStruct data)
{
    QSqlQuery query;
    QString command;
    uint32_t sqlTags=0;
    for(int i=0;i<NUMBER_OF_TAGS;i++)
    {
        if(data.tags[i]==true)
        {
            sqlTags|=(1<<i);
        }
    }
    command=QString("UPDATE games SET game_name=\"%1\", complexity=%2 ,randomness=%3, interaction=%4, "
            "game_time=%5, min_players=%6, max_palyers=%7, tags=%8 WHERE game_id=%9;")
            .arg(data.name).arg(data.numericVal[0]).arg(data.numericVal[1])
            .arg(data.numericVal[2]).arg(data.numericVal[3]).arg(data.numericVal[4])
            .arg(data.numericVal[5]).arg(sqlTags).arg(id+1);
    qDebug()<<command;
    query.exec(command);
}


GameDataBase::~GameDataBase()
{
    m_dataBase.close();
}
