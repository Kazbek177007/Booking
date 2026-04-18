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
    qWarning() << Q_FUNC_INFO <<"not finished";
}

void Cart::clear()
{
    qWarning() << Q_FUNC_INFO <<"not finished";
}
