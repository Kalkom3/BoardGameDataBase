#ifndef GAME_H
#define GAME_H

#define GRAFIC_ITEM_COUNT 8

#include <QPushButton>
#include <QGraphicsItem>
#include <vector>
#include <QFileDialog>
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <functional>
#include <QGraphicsScene>
#include <vector>

#include "GameView.h"



class Game
{

public:
    Game(QString _name,int _complexity,int _randomness,int _interaction, int _time, int _minPlayers, int _maxPlayers) ;
    GameView* gameWindow;
    QPushButton* activateButton;
    QImage* image[4];
    QGraphicsTextItem* labels[4]={new QGraphicsTextItem,new QGraphicsTextItem,new QGraphicsTextItem,new QGraphicsTextItem};
    QGraphicsPixmapItem* stars[3];
    std::vector<QGraphicsItem*>gitem;
    QString name;
    int pos[2];
    std::vector<int>properties;//complexity, randomness, interaction, time
    bool paramChanged;
    int minPlayers;
    int maxPlayers;
    int nr;
    static int g_nr;

    void checkParams();
    void openGameView(bool isModal);
    void setNewPos(int nr);
    ~Game();

};

#endif // GAME_H
