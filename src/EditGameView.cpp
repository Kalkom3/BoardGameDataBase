#include "EditGameView.h"
#include "ui_Gameview.h"

static int intPow(int value,int pow)
{
    if(!pow)
    {
        return 1;
    }
    if(!value)
    {
        return 0;
    }
    int product=value;
    for(int i=0;i<pow-1;i++)
    {
        product=product*value;
    }
    return product;
}

EditGameView::EditGameView(QWidget *parent) :
    GameView(parent)
{

}



EditGameView::EditGameView(Game *parentGame,bool* paramSave, QWidget *parent) :
     GameView(parent)
{
    gameProperties=&parentGame->getProperties();
    ui->nameEdit->setText(gameProperties->name);
    saveFlag=paramSave;
    for(int i=0;i<parentGame->gitem.size();i++)
    {
        gItems.push_back(CopyGraphicsItem(parentGame->gitem[i]));
        scene->addItem(gItems[i]);
    }
    for(int i=0;i<gameProperties->numericVal.size();i++)
    {
        sliders[i]->setValue(gameProperties->numericVal[i]);
    }
    for (int i=0;i<NUMBER_OF_TAGS;i++ )
    {
        tagBox[i]->setChecked(parentGame->getProperties().tags[i]);
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
        gameProperties->numericVal[i]=sliders[i]->value();
    }
    std::vector<bool>tempTags;
    for(int i=0;i<NUMBER_OF_TAGS;i++)
    {
        tempTags.push_back(tagBox[i]->isChecked());
    }
    gameProperties->tags=tempTags;
    gameProperties->name=ui->nameEdit->toPlainText();
    *saveFlag=true;
    emit saveChanges();
    this->close();
}

void EditGameView::on_delButton_clicked()
{
    this->close();
}


EditGameView::~EditGameView()
{
    delete ui;
}

