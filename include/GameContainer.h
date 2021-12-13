#ifndef GAME_CONTAINER_H
#define GAME_CONTAINER_H

#include "Game.h"
#include "Filters.h"
#include "GameDataBase.h"

#include <vector>
#include <fstream>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMainWindow>
#include <string>
#include <QGraphicsProxyWidget>
#include <QEvent>
#include <QTimer>

#include "GameView.h"

class Game_container : public QObject
{
    Q_OBJECT
public:
    Game_container(QGraphicsScene* _scene);


    GameDataBase* db;
    struct proxyButtons
    {
        QGraphicsProxyWidget* proxy;
        int nr;
    };
    std::vector<proxyButtons>gameButtons;
    std::vector<Game*>games;
    Filters gamesFilter;
    void add_game(Game* game);
    void show();
    void hide();
    void applyFilter();
    void applyTagFilter();

private:
    QGraphicsScene* gScene;
    std::vector<Game*>gamesToShow;
    QTimer* refTimer;
private slots:
    void refGame();
};

#endif // GAME_CONTAINER_H
