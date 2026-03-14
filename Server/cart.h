#ifndef CART_H
#define CART_H

#include <QObject>
#include "rep_user_source.h"

class Cart : public CartSimpleSource
{
    Q_OBJECT
public:
    explicit Cart(QObject *parent = nullptr);

signals:
};

#endif // CART_H
