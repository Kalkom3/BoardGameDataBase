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
    ~EditGameView();

private:
    propertiesStruct* gameProperties;
    std::vector<int*>propertiesPtr;
    std::vector<bool>*tagsPtr;
    QGraphicsItem* CopyGraphicsItem(QGraphicsItem* gItem);

signals:
    void saveChanges();

protected slots:

    virtual void on_editButton_clicked();
    virtual void on_delButton_clicked();

};

#endif // EDITGAMEVIEW_H
