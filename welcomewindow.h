#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QDialog>

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QDialog
{
    Q_OBJECT
    QString username;
    int age;

public:
    explicit WelcomeWindow(QString user , int age);
    explicit WelcomeWindow(QWidget *parent);


    ~WelcomeWindow();

private slots:
    void on_logout_clicked();

private:
    Ui::WelcomeWindow *ui;
};

#endif // WELCOMEWINDOW_H
