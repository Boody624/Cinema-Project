#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class RegisterPage;
}
QT_END_NAMESPACE

class RegisterPage : public QMainWindow
{
    Q_OBJECT

public:
    RegisterPage(QWidget *parent = nullptr);
    ~RegisterPage();

private slots:
    void on_registerButton_clicked();

private:
    Ui::RegisterPage *ui;
};
#endif // REGISTERPAGE_H
