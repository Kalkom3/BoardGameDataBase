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

namespace Ui {
class EditGameView;
}

class EditGameView : public GameView
{
    Q_OBJECT

public:

    explicit EditGameView(QWidget *parent = nullptr);
    explicit EditGameView(std::vector<QGraphicsItem*>gits,std::vector<int>&properties,bool* paramSave, QWidget *parent = nullptr);
    ~EditGameView();

protected slots:

    virtual void on_editButton_clicked();

private:
    std::vector<int*>propertiesPtr;
    QGraphicsItem* CopyGraphicsItem(QGraphicsItem* gItem);
};

#endif // EDITGAMEVIEW_H
