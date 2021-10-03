#include "GameView.h"
#include "ui_Gameview.h"

GameView::GameView(std::vector<QGraphicsItem*>gits,std::vector<int>&properties,bool* paramSave, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameView)
{
    ui->setupUi(this);
    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    for(int i=0;i<8;i++)
    {
        gItems.push_back(CopyGraphicsItem(gits[i]));
    }

    saveFlag=paramSave;
    for(int i=0;i<gItems.size();i++)
    {
        scene->addItem(gItems[i]);
    }

    sliders[0]=ui->horizontalSlider_1;
    sliders[1]=ui->horizontalSlider_2;
    sliders[2]=ui->horizontalSlider_3;
    sliders[3]=ui->horizontalSlider_4;
    for(int i=0;i<properties.size();i++)
    {
        propertiesPtr.push_back(&properties[i]);
        sliders[i]->setValue(properties[i]);
    }
    sLabels[0]=ui->sLabel1;
    sLabels[1]=ui->sLabel2;
    sLabels[2]=ui->sLabel3;
    sLabels[3]=ui->sLabel4;
    for(int i=0;i<4;i++)
    {
        setLabel(sliders[i],sLabels[i]);
    }

    connect(ui->horizontalSlider_1,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));
}




GameView::~GameView()
{
    delete ui;
}

void GameView::on_horizontalSlider_valueChanged(int value)
{

    for(int i=0;i<4;i++)
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


void GameView::on_editButton_clicked()
{
    for(int i=0;i<4;i++)
    {
        *propertiesPtr[i]=sliders[i]->value();
    }
    *saveFlag=true;
    this->close();
}



QGraphicsItem* GameView::CopyGraphicsItem(QGraphicsItem* gItem)
{
    if(gItem->type()==7)
    {
        QGraphicsPixmapItem* newGPM = new QGraphicsPixmapItem;
        QGraphicsPixmapItem* PixGitem=(QGraphicsPixmapItem*)gItem;
        newGPM->setPixmap(PixGitem->pixmap());
        newGPM->setScale(PixGitem->scale());
        newGPM->setPos(PixGitem->pos());

        return newGPM;
    }
    else if(gItem->type()==8)
    {
        QGraphicsTextItem* newGTI = new QGraphicsTextItem;
        QGraphicsTextItem* TextGitem=(QGraphicsTextItem*)gItem;
        newGTI->setPlainText(TextGitem->toPlainText());
        newGTI->setScale(TextGitem->scale());
        newGTI->setFont(TextGitem->font());
        newGTI->setPos(gItem->pos());
        return newGTI;
    }

    return nullptr;
}
