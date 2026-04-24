#include "cartproductpreview.h"
#include "cataloguewidget.h"
#include "client.h"
#include "productpreviewwidget.h"
#include "ui_cataloguewidget.h"

#include <qboxlayout.h>

CatalogueWidget::CatalogueWidget(QWidget *parent)
    : QScrollArea(parent)
    , ui(new Ui::CatalogueWidget)
{
    ui->setupUi(this);
    QWidget* widget = new QWidget;
    setWidget(widget);
    vBox = new QVBoxLayout;
    widget->setLayout(vBox);
    setWidgetResizable(true);
    qDebug() << "CatalogueWidget is created";
    connect(Client::instance()->catalogue.get(), &CatalogueReplica::productPreviewsChanged, this, &CatalogueWidget::updatePreviews);
}

CatalogueWidget::~CatalogueWidget()
{
    delete ui;
}

void CatalogueWidget::updatePreviews(QList<ProductPreview> productPreviews)
{
    while (auto item = vBox->takeAt(0))
    {
        item->widget()->deleteLater();
        delete item;
    }

    for (ProductPreview pp : productPreviews)
    {
        ProductPreviewWidget* ppw = new ProductPreviewWidget(pp);
        vBox->addWidget(ppw);
    }
    qDebug() << "Items to CatalogueWidget are added" << vBox->count();
}
