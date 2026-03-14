#pragma once
#include <QWidget>
#include <QVBoxLayout>

#include "rep_catalogue_replica.h"

class Catalogue : public QWidget
{
    Q_OBJECT
public:
    explicit Catalogue(QSharedPointer<CatalogueReplica> reptr);

private slots:
    void redraw();

private:
    QSharedPointer<CatalogueReplica> reptr;
    QVBoxLayout* mainLayout;
};

