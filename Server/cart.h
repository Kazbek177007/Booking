#pragma once
#include <QObject>
#include "rep_user_source.h"

class Cart : public CartSimpleSource
{
    Q_OBJECT
public:
    explicit Cart(QString clientId, QObject *parent = nullptr);
    void addItem(int id) override;
    void removeItem(int id) override;
    void clear() override;

private:
    QString clientId;

};

