#include "cartproductpreview.h"
#include "client.h"
#include "ui_cartproductpreview.h"

CartProductPreview::CartProductPreview(ProductPreview productPreview, int quantity)
    : ui(new Ui::CartProductPreview)
{
    ui->setupUi(this);
    QPixmap pixmap;
    pixmap.loadFromData(productPreview.icon());
    ui->icon->setPixmap(pixmap);
    ui->name->setText(productPreview.name());
    ui->quantity->setText(QString::number(quantity));
    ui->totalPrice->setText(QString::number(quantity * productPreview.price()));
    connect(ui->addItemButton, &QPushButton::clicked, [productPreview](){
        Client::instance()->cart->addItem(productPreview.id());
    });
    connect(ui->reduceItemButton, &QPushButton::clicked, [productPreview](){
        Client::instance()->cart->removeItem(productPreview.id());
    });
}

CartProductPreview::~CartProductPreview()
{
    delete ui;
}
