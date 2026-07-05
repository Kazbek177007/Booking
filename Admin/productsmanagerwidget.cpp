#include "productsmanagerwidget.h"
#include "ui_productsmanagerwidget.h"
#include "adminproductwidget.h"
#include "admin.h"

ProductsManagerWidget::ProductsManagerWidget(QWidget* parent)
    : QWidget(parent),
    ui(new Ui::ProductsManagerWidget)
{
    ui->setupUi(this);

    productListLayout = ui->productListLayout;

    auto listOfProducts = Admin::instance()->listOfProducts;
    connect(listOfProducts.get(), &ListOfProductsReplica::productsChanged,
            this, &ProductsManagerWidget::updateProducts);

    connect(ui->addProductButton, &QPushButton::clicked,
            this, &ProductsManagerWidget::addProductClicked);
}

ProductsManagerWidget::~ProductsManagerWidget()
{
    delete ui;
}

void ProductsManagerWidget::updateProducts(QList<Product> products)
{
    while (QLayoutItem* item = productListLayout->takeAt(0))
    {
        if (item->widget())
            item->widget()->deleteLater();
        delete item;
    }

    for (const Product& product : products) {
        AdminProductWidget* apw = new AdminProductWidget(product);
        productListLayout->addWidget(apw);
    }
    qDebug() << "[[Product List is updated"
}

void ProductsManagerWidget::addProductClicked()
{
    if (auto listOfProducts = Admin::instance()->listOfProducts)
        listOfProducts->addProduct();
}
