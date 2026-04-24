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
}

CartWidget::~CartWidget()
{
    delete ui;
}

void CartWidget::updateCart()
{
    while (auto item = layout()->takeAt(0))
    {
        item->widget()->deleteLater();
        delete item;
    }
    QList<ProductPreview> pp = Client::instance()->catalogue->productPreviews();

    for (auto i : pp)
    {
        int quantity = Client::instance()->cart->items().value(i.id());
        if (quantity > 0)
        {
        CartProductPreview* cpp = new CartProductPreview(i, quantity);
        CartWidget::ui->verticalLayout->addWidget(cpp);
        }
    }

}
