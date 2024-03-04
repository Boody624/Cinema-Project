#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QString user, int age) : QDialog(nullptr), ui(new Ui::WelcomeWindow) {
    ui->setupUi(this); // Initialize UI components

    QString str = QString::number(age);
    ui->hellolabel->setText("Hello " + user + " " + str);

    QPixmap pix("D:\\AUC\\Spring 2024\\CS 2 Lab\\Cinema\\popcorn.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

WelcomeWindow::WelcomeWindow(QWidget *parent) : QDialog(parent), ui(new Ui::WelcomeWindow) {
    ui->setupUi(this); // Initialize UI components
}

WelcomeWindow::~WelcomeWindow() {
    delete ui;
}

void WelcomeWindow::on_logout_clicked() {
    this->hide();
    LoginWindow* loginWindow = new LoginWindow(this);
    loginWindow->show();
}
