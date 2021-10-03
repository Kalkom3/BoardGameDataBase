#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <vector>
#include <QSlider>
#include <QLabel>



namespace Ui {
class GameView;
}

class GameView : public QDialog
{
    Q_OBJECT

public:
    explicit GameView(std::vector<QGraphicsItem*>gits,std::vector<int>&properties,bool* paramSave,QWidget *parent = nullptr);
    QGraphicsScene *scene;
    QSlider* sliders[4];
    QLabel* sLabels[4];
    std::vector<int*>propertiesPtr;
    QGraphicsTextItem *labels[4]={new QGraphicsTextItem,new QGraphicsTextItem,new QGraphicsTextItem,new QGraphicsTextItem};
    std::vector<QGraphicsItem*>gItems;
    int itemCounter;
    bool* saveFlag;
    ~GameView();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_editButton_clicked();


private:
    Ui::GameView *ui;
    void setLabel(QSlider* slider,QLabel* label);
    QGraphicsItem* CopyGraphicsItem(QGraphicsItem* gItem);
};

#endif // GAMEVIEW_H
