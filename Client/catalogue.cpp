#include "catalogue.h"
#include <QLabel>

Catalogue::Catalogue(QSharedPointer<CatalogueReplica> reptr) : reptr(reptr)
{
    connect(reptr.get(), &CatalogueReplica::productPreviewsChanged, this, &Catalogue::redraw);
    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);
    connect(reptr.get(), &CatalogueReplica::initialized,[reptr]()
            {
                QString myId = QUuid::createUuid().toString(QUuid::WithoutBraces).left(8);
                reptr->registerClient(myId);
            });

}

void Catalogue::redraw()
{
    while(QLayoutItem* item = mainLayout->takeAt(0))
        delete item;

    QList<ProductPreview> products = reptr->productPreviews();
    for(auto product : products)
    {
        auto hbox = new QHBoxLayout;
        hbox->addWidget(new QLabel(QString::number(product.id())));
        hbox->addWidget(new QLabel(product.name()));
        hbox->addWidget(new QLabel(QString::number(product.price())));
        mainLayout->addLayout(hbox);
    }
}
