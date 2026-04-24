#ifndef CARTPRODUCTPREVIEW_H
#define CARTPRODUCTPREVIEW_H

#include "rep_catalogue_replica.h"
#include <QWidget>

namespace Ui {
class CartProductPreview;
}

class CartProductPreview : public QWidget
{
    Q_OBJECT

public:
    explicit CartProductPreview(ProductPreview productPreview, int quantity);
    ~CartProductPreview();

private:
    Ui::CartProductPreview *ui;
};

#endif
