#include "cartproductpreview.h"
#include "cartwidget.h"
#include "client.h"
#include "ui_cartwidget.h"

CartWidget::CartWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CartWidget)
{
    ui->setupUi(this);
    connect(Client::instance()->cart.get(), &CartReplica::itemsChanged, this, &CartWidget::updateCart);
    connect(ui->buyButton, &QPushButton::clicked,  []()
            {
                    Client::instance()->orderHistory->createOrder(Client::instance()->cart->items());
                    Client::instance()->cart->clear();
            });
}

CartWidget::~CartWidget()
{
    delete ui;
}

void CartWidget::updateCart()
{
    while (auto item = ui->itemsLayout->takeAt(0))
    {
        item->widget()->deleteLater();
        delete item;
    }

    QMap<int, int> items = Client::instance()->cart->items();

    for (auto [id, quantity] : items.asKeyValueRange())
    {
        ProductPreview pp = Client::instance()->productPreview(id);
        CartProductPreview* cpp = new CartProductPreview(pp, quantity);
        ui->itemsLayout->addWidget(cpp);
    }
    qDebug() << "Current cart" << items;
}
