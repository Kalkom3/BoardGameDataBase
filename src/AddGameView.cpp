#include "AddGameView.h"
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

AddGameView::AddGameView(QWidget *parent) :
    GameView(parent)
{
    ui->delButton->hide();
}


void AddGameView::on_editButton_clicked()
{
    properties.name=ui->nameEdit->toPlainText();
    for(int i=0;i<NUMBER_OF_SLIDERS;i++)
    {
        properties.numericVal.push_back(sliders[i]->value());
    }
    std::vector<bool>tempTags;
    for(int i=0;i<NUMBER_OF_TAGS;i++)
    {
        tempTags.push_back(tagBox[i]->isChecked());
    }
    properties.tags=tempTags;
    emit saveGame(properties);
    this->close();
}


AddGameView::~AddGameView()
{
    delete ui;
}
