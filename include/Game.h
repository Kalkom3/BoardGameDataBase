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
#include "PropertiesStruct.h"


class Game
{

public:
    Game(propertiesStruct _properties);
    QPushButton* activateButton;
    bool isVisible;
    std::vector<QGraphicsItem*>gitem;
    bool paramChanged;
    int nr;
    static int g_nr;
    propertiesStruct& getProperties();
    void openGameView(bool isModal);
    void setNewPos(int nr);
    ~Game();
private:
    int pos[2];
    QImage* image[4];
    propertiesStruct gameProperties;
    QGraphicsTextItem* labels[4]={new QGraphicsTextItem,new QGraphicsTextItem,new QGraphicsTextItem,new QGraphicsTextItem};
    QGraphicsPixmapItem* stars[3];
    void checkParams();
    void init();

};

#endif // GAME_H
