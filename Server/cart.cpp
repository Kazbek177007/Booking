#include "cart.h"

Cart::Cart(QObject *parent)
    : CartSimpleSource{parent}
{}

void Cart::addItem(int id)
{
    qWarning() << Q_FUNC_INFO <<"not finished";
}

void Cart::removeItem(int id)
{
    qWarning() << Q_FUNC_INFO <<"not finished";
}

void Cart::clear()
{
    qWarning() << Q_FUNC_INFO <<"not finished";
}
