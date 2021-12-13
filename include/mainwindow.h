#ifndef MAINWINDOW_H
#define MAINWINDOW_H



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
#include "ui_mainwindow.h"
#include "GameContainer.h"

constexpr int NUMBER_OF_FILTERS = 5;
constexpr int SQL_RETURN_LEN = 1000;

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
    void on_checkBox_stateChanged(int state);
    void on_clearFiltersButton_clicked();


    void on_addButton_clicked();

private:
    std::vector<QCheckBox*>tagBox;
    AddGameView* addGameWindow;
    Game_container* container;
    void init();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
