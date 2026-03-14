#ifndef ORDERHISTORY_H
#define ORDERHISTORY_H

#include <QObject>
#include <rep_user_source.h>

class OrderHistory : public OrderHistorySimpleSource
{
    Q_OBJECT
public:
    explicit OrderHistory(QObject *parent = nullptr);

signals:
};

#endif // ORDERHISTORY_H
