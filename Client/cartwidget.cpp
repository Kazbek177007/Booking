#include "cartwidget.h"
#include "client.h"
#include "ui_cartwidget.h"

CartWidget::CartWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CartWidget)
{
    ui->setupUi(this);
    connect(Client::instance()->cart.get(), &CartReplica::itemsChanged, this, &CartWidget::updateCart);
}

CartWidget::~CartWidget()
{
    delete ui;
}

void CartWidget::updateCart()
{
    auto tempM = Client::instance()->cart->items();
    qDebug() << tempM;
}
