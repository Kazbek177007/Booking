#pragma once
#include <QObject>
#include "rep_catalogue_source.h"


class Catalogue : public CatalogueSimpleSource
{
    Q_OBJECT
public:
    Catalogue();
    void registerClient(QString clientId) override;
};


