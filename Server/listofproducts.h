#ifndef LISTOFPRODUCTS_H
#define LISTOFPRODUCTS_H

#include <QObject>

class ListOfProducts : public QObject
{
    Q_OBJECT
public:
    explicit ListOfProducts(QObject *parent = nullptr);

signals:
};

#endif // LISTOFPRODUCTS_H
