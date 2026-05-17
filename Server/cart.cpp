#include "cart.h"

Cart::Cart(QString clientId, QObject *parent)
    : CartSimpleSource{parent},
    clientId(clientId)
{}

void Cart::addItem(int id)
{
    auto tempItems = items();
    tempItems[id] += 1;
    setItems(tempItems);
    qDebug() << "Client with Id" << clientId << "buy item" << id;
}

void Cart::removeItem(int id)
{
    auto tempItems = items();
    tempItems[id] -= 1;
    if(tempItems[id] <= 0) tempItems.remove(id);
    setItems(tempItems);
    qDebug() << "Client with id" << clientId << "remove the item:" << id;
}

void Cart::clear()
{
    setItems(QMap<int, int>());
    qDebug() << "Client with id" << clientId << "cleared the cart";
}
