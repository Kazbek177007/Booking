#include "userprofilewidget.h"
#include "ui_userprofilewidget.h"

UserProfileWidget::UserProfileWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserProfileWidget)
{
    ui->setupUi(this);
}

UserProfileWidget::~UserProfileWidget()
{
    delete ui;
}
