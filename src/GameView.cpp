#include "GameView.h"
#include "ui_Gameview.h"

GameView::GameView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameView)
{
    ui->setupUi(this);
    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);

    sliders[0]=ui->horizontalSlider_1;
    sliders[1]=ui->horizontalSlider_2;
    sliders[2]=ui->horizontalSlider_3;
    sliders[3]=ui->horizontalSlider_4;
    sliders[4]=ui->horizontalSlider_5;
    sliders[5]=ui->horizontalSlider_6;


    sLabels[0]=ui->sLabel1;
    sLabels[1]=ui->sLabel2;
    sLabels[2]=ui->sLabel3;
    sLabels[3]=ui->sLabel4;
    sLabels[4]=ui->sLabel5;
    sLabels[5]=ui->sLabel6;
    int numberOfTags=0;
    for(Tag tag : tags)
    {
        tagBox.push_back(new QCheckBox(tag.tagName));
        ui->tagsLayout->addWidget(tagBox[numberOfTags],numberOfTags);
        numberOfTags++;
    }

    for(int i=0;i<NUMBER_OF_SLIDERS;i++)
    {
        setLabel(sliders[i],sLabels[i]);
    }

    connect(ui->horizontalSlider_1,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_5,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_6,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
}



void GameView::on_horizontalSlider_valueChanged(int value)
{
    for(int i=0;i<NUMBER_OF_SLIDERS;i++)
    {
        setLabel(sliders[i],sLabels[i]);
    }
}



void GameView::setLabel(QSlider* slider,QLabel* label)
{
    QString SLtext=label->text();
    SLtext.chop(1);
    label->setText(SLtext+QString::number(slider->value()));
}



GameView::~GameView()
{
    delete ui;
}
