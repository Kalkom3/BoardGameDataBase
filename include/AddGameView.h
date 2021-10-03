#ifndef ADDGAMEVIEW_H
#define ADDGAMEVIEW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <vector>
#include <QSlider>
#include <QLabel>

namespace Ui {
class AddGameView;
}

class AddGameView : public QDialog
{
    Q_OBJECT

public:
    explicit AddGameView(QWidget *parent = nullptr);
    ~AddGameView();

private:
    QGraphicsScene *scene;
    QSlider* sliders[4];
    QLabel* sLabels[4];
    Ui::AddGameView *ui;
};

#endif // ADDGAMEVIEW_H
