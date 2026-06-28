#pragma once

#include <QObject>
#include "rep_admin_source.h"
class ListOfProducts : public ListOfProductsSimpleSource
{
    Q_OBJECT
public:
    explicit ListOfProducts(QObject *parent = nullptr);

private:
    void addProduct() override;
    void changeProductInfo(Product) override;
    void removeProduct(int id) override;

signals:
};
