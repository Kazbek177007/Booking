#include "client.h"
#include "productpreviewwidget.h"
#include "ui_productpreviewwidget.h"

ProductPreviewWidget::ProductPreviewWidget(ProductPreview productPreview)
    : ui(new Ui::ProductPreviewWidget)
{
    ui->setupUi(this);

    QPixmap pixmap;
    pixmap.loadFromData(productPreview.icon());
    ui->icon->setPixmap(pixmap);
    ui->productName->setText(productPreview.name());
    ui->productPrice->setText(QString::number(productPreview.price()));
    qDebug() << productPreview;
    connect(ui->addProductButton, &QPushButton::clicked, [productPreview](){
        Client::instance()->cart->addItem(productPreview.id());
    });
}

ProductPreviewWidget::~ProductPreviewWidget()
{
    delete ui;
}
