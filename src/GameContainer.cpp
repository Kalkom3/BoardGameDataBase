#include "GameContainer.h"

Game_container::Game_container(QGraphicsScene* _scene)
{
    db=new GameDataBase;
    std::vector<Game*>gamesToAdd = db->GetAllGames();
    for(int i=0;i<gamesToAdd.size();i++)
    {
        add_game(gamesToAdd[i]);
    }
    refTimer = new QTimer;
    connect(refTimer,SIGNAL(timeout()),this,SLOT(refGame()));
    gScene=_scene;
    refTimer->start(300);
}



/*!
 * \brief Game_container::add_game - Funkcja dodaję gre do kontenera
 * \param QGraphicsScene - widok
 */
void Game_container::add_game(Game* game)
{
    games.push_back(game);
    gamesToShow.push_back(game);
    proxyButtons newButton;
    newButton.nr=game->nr;
    newButton.proxy=nullptr;
    gameButtons.push_back(newButton);
    QObject::connect(game->activateButton,&QPushButton::clicked,std::bind(&Game::openGameView,game,true));

}



/*!
 * \brief Game_container::show - Funkcja pokazuje wybrane przez inne funkcje gry(domyślnie wszystkie)
 * \param QGraphicsScene - widok
 */
void Game_container::show()
{
    for(int i=0;i<gamesToShow.size();i++)
    {
        gamesToShow[i]->setNewPos(i);
        for(int j=0;j<8;j++)
        {
            gScene->addItem(gamesToShow[i]->gitem[j]);
            //qDebug()<<i<<","<<j<<":";
            //qDebug()<<gamesToShow[i]->gitem[j]->pos();
        }
        for(int j=0;j<gameButtons.size();j++)
        {
            if(gameButtons[j].nr==gamesToShow[i]->nr)
            {
                if(gameButtons[j].proxy==nullptr)
                {
                    gameButtons[j].proxy=gScene->addWidget(gamesToShow[i]->activateButton);
                }
                gameButtons[j].proxy->show();
            }
        }

    }
}



/*!
 * \brief Game_container::hide - Funkcja ukrywa wybrane gry z widoku
 * \param QGraphicsScene - widok
 */
void Game_container::hide()
{
    for(int i=0;i<gamesToShow.size();i++)
    {
        for(int j=0;j<8;j++)
        {
            gScene->removeItem(gamesToShow[i]->gitem[j]);
        }
        for(int j=0;j<gameButtons.size();j++)
        {
            gameButtons[j].proxy->hide();
        }
    }
}



/*!
 * \brief Game_container::applyFilter - Funkcja włącza działanie fitra na kontenerze
 * \param QGraphicsScene - widok
 */
void Game_container::applyFilter()
{
    gamesToShow.clear();
    bool filterOK=false;
    for(int i=0;i<games.size();i++)
    {
        filterOK=true;
        for(int j=0;j<NUMBER_OF_PROPERTIES;j++)
        {
            if(gamesFilter.properties[j]!=(-1))
            {
                if(j!=NUMBER_OF_PROPERTIES-1)
                {
                    if(games[i]->properties[j]!=gamesFilter.properties[j])
                    {
                        filterOK=false;
                        break;
                    }
                }
                else
                {
                    if(gamesFilter.properties[j]<games[i]->properties[j] || gamesFilter.properties[j]>games[i]->properties[j+1])
                    {
                        filterOK=false;
                        break;
                    }
                }

            }

        }
        if(filterOK==true)
        {
            gamesToShow.push_back(games[i]);
        }
    }
}



void Game_container::refGame()
{
    int params[4];
    for(int i=0;i<gamesToShow.size();i++)
    {
        if(gamesToShow[i]->paramChanged==true)
        {
            qDebug()<<"del";
            gamesToShow[i]->paramChanged=false;
            for(int j=1;j<8;j++)
            {
                if(j>3)
                {
                  gScene->removeItem(gamesToShow[i]->gitem[j]);
                }

                gScene->addItem(gamesToShow[i]->gitem[j]);

            }
            db->ModifyGame(i+1,gamesToShow[i]->properties[0],gamesToShow[i]->properties[1],
                    gamesToShow[i]->properties[2],gamesToShow[i]->properties[3],gamesToShow[i]->properties[4],
                    gamesToShow[i]->properties[5]);
            break;
        }
    }
}
