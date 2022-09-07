#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <vector>
#include <QSlider>
#include <QLabel>
#include <QCheckBox>

#include "PropertiesStruct.h"
#include "Tags.h"
constexpr int NUMBER_OF_SLIDERS = 6;

namespace Ui {
class GameView;
}

class GameView : public QDialog
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = nullptr);

    QGraphicsTextItem *labels[4]={new QGraphicsTextItem,new QGraphicsTextItem,new QGraphicsTextItem,new QGraphicsTextItem};
    std::vector<QGraphicsItem*>gItems;
    int itemCounter;
    bool* saveFlag;
    ~GameView();
    Ui::GameView *ui;

protected:
    std::vector<QCheckBox*>tagBox;
    propertiesStruct properties;
    QGraphicsScene *scene;
    void setLabel(QSlider* slider,QLabel* label);
    QSlider* sliders[NUMBER_OF_SLIDERS];
    QLabel* sLabels[NUMBER_OF_SLIDERS];


protected slots:
    void on_horizontalSlider_valueChanged(int value);

    virtual void on_editButton_clicked()=0;
    virtual void on_delButton_clicked()=0;

};

#endif // GAMEVIEW_H
