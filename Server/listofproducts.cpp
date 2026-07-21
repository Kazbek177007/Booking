#include "listofproducts.h"
#include "database.h"
#include <algorithm>

ListOfProducts::ListOfProducts(QObject* parent) : ListOfProductsSimpleSource(parent)
{}

void ListOfProducts::addProduct()
{
    Product product;
    int id = Database::instance().addProduct(product);
    ProductPreview pw;
    pw.setId(id);
    product.setPreview(pw);

    auto lop = products();
    lop.append(product);
    setProducts(lop);

    qDebug() << "add Product()";
}

void ListOfProducts::changeProductInfo(Product p)
{
    Database::instance().updateProduct(p);
    auto lop = products();
    auto it = std::find_if(lop.begin(), lop.end(), [p](Product x)
    {
        return p.preview().id() == x.preview().id();
    });
    *it = p;
    setProducts(lop);

    qDebug() << "Id " <<  p.preview().id() << "has changed";
}

void ListOfProducts::removeProduct(int id)
{

}
