#include "loginwindow.h"
#include "welcomewindow.h"
#include "ui_loginwindow.h"
#include "users.h"
#include "registerpage.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui -> error -> setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_login_clicked()
{
    QString user;
    int age = 0;
    bool success = false;
    QString name = ui->userline->text();
    QString pass = ui->passline->text();
    for(int i =0; i<usersCount; i++)
    {
        if(name == usernames[i] && pass == passwords[i])
        {
            success = true;
            age = ages[i];
            break ;
        }

    }
    user = name;
    if(success == true){
        this->hide();
        WelcomeWindow* welcomeWindow = new WelcomeWindow(user, age);
        welcomeWindow->show();
    }
    else{
        ui->error->setVisible(true);
    }

}


void LoginWindow::on_register_2_clicked()
{
    this->hide();
    RegisterPage* registerWindow = new RegisterPage();
    registerWindow->show();

}


