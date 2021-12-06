#include "AddGameView.h"
#include "ui_Gameview.h"

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
    emit saveGame(properties);
    this->close();
}

AddGameView::~AddGameView()
{
    delete ui;
}
