#include "LoginView.h"
#include "ui_LoginView.h"

#include <QMessageBox>

LoginView::LoginView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);
    connect(ui->loginButton,SIGNAL(clicked()),this,SLOT(onLoginButtonClicked()));
    connect(ui->offlineButton,SIGNAL(clicked()),this,SLOT(onOfflineButtonClicked()));
    connect(ui->autofillButton,SIGNAL(clicked()),this,SLOT(onAutofillButtonClicked()));
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::onLoginButtonClicked()
{
    loginCredentials loginCredentials = {
        ui->hostInput->text(),
        ui->userInput->text(),
        ui->passwordInput->text(),
        ui->databaseInput->text(),
        ui->portInput->text().toInt()
    };
    emit tryLogin(loginCredentials);

}

void LoginView::onOfflineButtonClicked()
{

}

void LoginView::onAutofillButtonClicked()
{
    ui->userInput->setText("root");
    ui->hostInput->setText("localhost");
    ui->portInput->setText("3306");
}

void LoginView::onLoginSucces()
{
    this->close();
}

void LoginView::onLoginFailed(QString errorMessage)
{
    QMessageBox errorBox;
    errorBox.setIcon(QMessageBox::Critical);
    errorBox.setText(errorMessage);
    errorBox.exec();
}
