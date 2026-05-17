#pragma once
#include <QObject>
#include <rep_user_source.h>

class OrderHistory : public OrderHistorySimpleSource
{
    Q_OBJECT
public:
    explicit OrderHistory(QString clientId, QObject *parent = nullptr);

signals:

private:
    QString clientId;

private slots:
    void createOrder(QMap<int, int> items) override;
};
