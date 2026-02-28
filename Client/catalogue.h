#pragma once
#include <QWidget>
#include <QVBoxLayout>

#include "rep_catalogue_replica.h"

class Catalogue : public QWidget
{
    Q_OBJECT
public:
    explicit Catalogue(QSharedPointer<CatalogueReplica> reptr);


private:
    QSharedPointer<CatalogueReplica> reptr;
    QVBoxLayout* mainLayout;
signals:

private slots:
    void redraw();

};

