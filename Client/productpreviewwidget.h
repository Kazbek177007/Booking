#ifndef PRODUCTPREVIEWWIDGET_H
#define PRODUCTPREVIEWWIDGET_H

#include <QWidget>
#include "rep_catalogue_replica.h"

namespace Ui {
class ProductPreviewWidget;
}

class ProductPreviewWidget : public QWidget
{
    Q_OBJECT

public:
    ProductPreviewWidget(ProductPreview productPreview);
    ~ProductPreviewWidget();

private:
    Ui::ProductPreviewWidget *ui;
};

#endif // PRODUCTPREVIEWWIDGET_H
