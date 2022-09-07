#ifndef ADDGAMEVIEW_H
#define ADDGAMEVIEW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <vector>
#include <QSlider>
#include <QLabel>

#include "GameView.h"

namespace Ui {
class AddGameView;
}

class AddGameView : public GameView
{
    Q_OBJECT

public:
    explicit AddGameView(QWidget *parent = nullptr);
    ~AddGameView();
signals:
    void saveGame(propertiesStruct _properties);

protected slots:
    virtual void on_delButton_clicked(){};
    virtual void on_editButton_clicked();

private:
    QGraphicsScene *scene;
};

#endif // ADDGAMEVIEW_H
