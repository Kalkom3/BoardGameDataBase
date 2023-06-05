#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QDialog>

struct loginCredentials{
    QString hostname;
    QString username;
    QString password;
    QString databaseName;
    int port;

};

namespace Ui {
class LoginView;
}

class LoginView : public QDialog
{
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = nullptr);
    ~LoginView();

private:
    Ui::LoginView *ui;

signals:
    void tryLogin(loginCredentials);

private slots:
    void onLoginButtonClicked();
    void onOfflineButtonClicked();
    void onAutofillButtonClicked();
    void onLoginSucces();
    void onLoginFailed(QString);
};

#endif // LOGINVIEW_H
