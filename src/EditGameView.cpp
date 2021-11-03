#include "EditGameView.h"
#include "ui_Gameview.h"

EditGameView::EditGameView(QWidget *parent) :
    GameView(parent)
{

}



EditGameView::EditGameView(std::vector<QGraphicsItem*>gits,std::vector<int>&properties,bool* paramSave, QWidget *parent) :
    GameView(parent)
{

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



    for(int i=0;i<properties.size();i++)
    {
        propertiesPtr.push_back(&properties[i]);
        sliders[i]->setValue(properties[i]);
    }


}



QGraphicsItem* EditGameView::CopyGraphicsItem(QGraphicsItem* gItem)
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

void EditGameView::on_editButton_clicked()
{
    for(int i=0;i<NUMBER_OF_SLIDERS;i++)
    {
        *propertiesPtr[i]=sliders[i]->value();
    }
    *saveFlag=true;
    this->close();
}

EditGameView::~EditGameView()
{
    delete ui;
}

