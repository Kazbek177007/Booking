#include "orderhistory.h"

OrderHistory::OrderHistory(QString clientId, QObject *parent)
    : OrderHistorySimpleSource{parent},
    clientId(clientId)
{}

void OrderHistory::createOrder(QMap<int, int> items)
{
    if(items.empty())
    {
        qWarning() << "The cart is empty";
        return;
    }
    Order order (items, QDateTime::currentDateTimeUtc());
    auto ordersList = orders();
    ordersList.append(order);
    setOrders(ordersList);
    qDebug() << "Client with Id:" << clientId << "made an order" << order;
}
