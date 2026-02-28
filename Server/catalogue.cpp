#include "catalogue.h"



Catalogue::Catalogue()
{
    setProductPreviews({ProductPreview(1, "Ball", QByteArray(), 100),
                        ProductPreview(2, "Doll", QByteArray(), 200),
                        ProductPreview(3, "Socks",QByteArray(), 500)});


    QTimer* stateChangeTimer = new QTimer(this); // Initialize timer
    QObject::connect(stateChangeTimer, &QTimer::timeout, [this]()
                     {
                        setProductPreviews(productPreviews()+QList({ProductPreview(4, "Car", QByteArray(), 1000)}));
                     }); // connect timeout() signal from stateChangeTimer to timeout_slot() of simpleSwitch
    stateChangeTimer->start(2000); // Start timer and set timout to 2 seconds
}
