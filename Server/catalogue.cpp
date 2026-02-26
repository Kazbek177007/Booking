#include "catalogue.h"



Catalogue::Catalogue()
{
    setProductPreviews({ProductPreview(1, "Ball", QByteArray(), 100),
                        ProductPreview(2, "Doll", QByteArray(), 200),
                        ProductPreview(3, "Socks",QByteArray(), 500)});
}
