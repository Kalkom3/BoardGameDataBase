#include "AddGameView.h"
#include "ui_Gameview.h"

AddGameView::AddGameView(QWidget *parent) :
    GameView(parent)
{
    ui->delButton->hide();
}


void AddGameView::on_editButton_clicked()
{

}

AddGameView::~AddGameView()
{
    delete ui;
}
