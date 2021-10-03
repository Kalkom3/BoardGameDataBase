#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define NUMBER_OF_FILTERS 5
#define SQL_RETURN_LEN 1000

#include <QMainWindow>
#include <QGraphicsItem>
#include <vector>
#include <QFileDialog>
#include <QLabel>
#include <QRectF>
#include <QWidget>
#include <QSlider>
#include <QCheckBox>
#include <QEvent>

#include "AddGameView.h"
#include "GameDataBase.h"
#include "ui_mainwindow.h"
#include "Game.h"
#include "Filters.h"
#include "GameContainer.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget* test;
    QSlider* sliders[NUMBER_OF_PROPERTIES+1];
    QLabel* labels[NUMBER_OF_PROPERTIES+1];
    QGraphicsScene *scene;

    std::vector<QGraphicsRectItem*>rects;


private slots:


    void on_horizontalSlider_valueChanged(int value);

    void on_clearFiltersButton_clicked();


    void on_addButton_clicked();

private:
    AddGameView* addGameWindow;
    Game_container* container;
    void init();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
