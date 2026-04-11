#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    ui->phoneNumber->setInputMask("+7(999)999-99-99");
    ui->phoneNumber->setPlaceholderText("+7(___)___-__-__");
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

QString LoginWidget::phoneNumber() const
{
    return ui->phoneNumber->text();
}
