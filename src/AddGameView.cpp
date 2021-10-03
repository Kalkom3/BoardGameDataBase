#include "AddGameView.h"
#include "ui_Addgameview.h"

AddGameView::AddGameView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGameView)
{
    ui->setupUi(this);
}

AddGameView::~AddGameView()
{
    delete ui;
}
