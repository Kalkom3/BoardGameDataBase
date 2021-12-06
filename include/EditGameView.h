#ifndef EDITGAMEVIEW_H
#define EDITGAMEVIEW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <vector>
#include <QSlider>
#include <QLabel>
#include "GameView.h"
#include "Game.h"

namespace Ui {
class EditGameView;
}

class EditGameView : public GameView
{
    Q_OBJECT

public:

    explicit EditGameView(QWidget *parent = nullptr);
    explicit EditGameView(Game *parentGame,bool* paramSave, QWidget *parent = nullptr);
    explicit EditGameView(std::vector<QGraphicsItem*>gits,std::vector<int>&properties,bool* paramSave, QWidget *parent = nullptr);
    ~EditGameView();

private:
    std::vector<int*>propertiesPtr;
    QGraphicsItem* CopyGraphicsItem(QGraphicsItem* gItem);

signals:
    void saveChanges();

protected slots:

    virtual void on_editButton_clicked();


};

#endif // EDITGAMEVIEW_H
