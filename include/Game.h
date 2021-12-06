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

#include "EditGameView.h"



class Game
{

public:
    Game(propertiesStruct _properties);
    QPushButton* activateButton;
    bool isVisible;
    std::vector<QGraphicsItem*>gitem;
    QString name;
    std::vector<int>properties;//complexity, randomness, interaction, time, min PL, max PL, name
    bool paramChanged;
    int nr;
    static int g_nr;

    void checkParams();
    void openGameView(bool isModal);
    void setNewPos(int nr);
    ~Game();

};

#endif // GAME_H
