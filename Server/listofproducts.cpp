#include "listofproducts.h"

ListOfProducts::ListOfProducts(QObject* parent) : ListOfProductsSimpleSource(parent)
{}

void ListOfProducts::addProduct()
{
    qDebug() << "add Product";
}

void ListOfProducts::changeProductInfo(Product)
{

}

void ListOfProducts::removeProduct(int id)
{

}
