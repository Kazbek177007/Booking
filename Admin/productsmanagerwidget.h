#pragma once
#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "rep_admin_replica.h"

namespace Ui {
class ProductsManagerWidget;
}

class ProductsManagerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProductsManagerWidget(QWidget* parent = nullptr);
    ~ProductsManagerWidget();

private slots:
    void updateProducts(QList<Product> products);
    void addProductClicked();

private:
    Ui::ProductsManagerWidget* ui;
    QVBoxLayout* productListLayout;
};