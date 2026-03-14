#ifndef CART_H
#define CART_H

#include <QObject>
#include "rep_user_source.h"

class Cart : public CartSimpleSource
{
    Q_OBJECT
public:
    explicit Cart(QObject *parent = nullptr);
    void addItem(int id) override;
    void removeItem(int id) override;
    void clear() override;
};

#endif // CART_H
