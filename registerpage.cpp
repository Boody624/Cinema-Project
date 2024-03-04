#include "registerpage.h"
#include "ui_registerpage.h"
#include "Users.h"
#include "welcomewindow.h"

RegisterPage::RegisterPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterPage)
{
    ui->setupUi(this);
    ui->Error_Age->hide();
    ui->Error_Check->hide();
    ui->Error_Password->hide();
    ui->Error_Username->hide();
}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::on_registerButton_clicked()
{
    ui->Error_Age->hide();
    ui->Error_Check->hide();
    ui->Error_Password->hide();
    ui->Error_Username->hide();

   QString uname =  ui->UserName->text();
   QString pass =  ui->Password->text();
   QString repass =  ui->Repassword->text();
   QString year = ui->year->text();
   int age = year.toInt();

   if (pass != repass)
       ui->Error_Password->show();

   for (int i = 0; i < usersCount; ++i)
   {
       if (uname == usernames[i])
           ui->Error_Username->show();
   }
   if (2024 - age < 12)
       ui->Error_Age->show();
   if (ui->male->isChecked()==false && ui->female->isChecked()==false)
       ui->Error_Check->show();

   else if (ui->user_account->isChecked()==false && ui->admin_account->isChecked()==false)
       ui->Error_Check->show();

   else if (ui->action->isChecked()==false && ui->drama->isChecked()==false && ui->anime->isChecked()==false && ui->comedy->isChecked()==false && ui->horror->isChecked()==false && ui->other->isChecked()==false)
       ui->Error_Check->show();

   else{
   usernames[usersCount] = uname;
   passwords[usersCount] = pass;
   ages[usersCount] = 2024 - age;
   usersCount++;
   this->hide();
   WelcomeWindow* welcomeWindow = new WelcomeWindow(uname, 2024-age);
   welcomeWindow -> show();
   }
}

