#include "mainwindow.h"
#include "AddGameView.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int game_width=200,game_height=350;
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    container = new Game_container(scene);

    init();

    container->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    sliders[0]=ui->horizontalSlider;
    sliders[1]=ui->horizontalSlider_2;
    sliders[2]=ui->horizontalSlider_3;
    sliders[3]=ui->horizontalSlider_4;
    sliders[4]=ui->horizontalSlider_5;

    labels[0]=ui->label;
    labels[1]=ui->label_2;
    labels[2]=ui->label_3;
    labels[3]=ui->label_4;
    labels[4]=ui->label_5;


    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_5,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));

}



void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    for(int i=0;i<NUMBER_OF_PROPERTIES;i++)
    {
        container->gamesFilter.setFilter(*sliders[i],*labels[i]);
    }
    container->hide();
    container->applyFilter();
    container->show();
}




void MainWindow::on_clearFiltersButton_clicked()
{
    for(int i=0;i<NUMBER_OF_FILTERS;i++)
    {
        container->gamesFilter.clearFilter(*sliders[i]);
    }
}





void MainWindow::on_addButton_clicked()
{
    AddGameView* addGameDialog = new AddGameView();
    connect(addGameDialog,&AddGameView::saveGame,this,[&](propertiesStruct properties){
        container->db->AddGame(container->games.size()+1,properties);
        Game* game=new Game(properties);
        container->add_game(game);
        container->show();
    });
    addGameDialog->exec();

}
