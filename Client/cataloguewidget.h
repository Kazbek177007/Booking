#ifndef CATALOGUEWIDGET_H
#define CATALOGUEWIDGET_H

#include <QScrollArea>
#include <QVBoxLayout>
#include <rep_catalogue_replica.h>

namespace Ui {
class CatalogueWidget;
}

class CatalogueWidget : public QScrollArea
{
    Q_OBJECT

public:
    explicit CatalogueWidget(QWidget *parent = nullptr);
    ~CatalogueWidget();

private:
    Ui::CatalogueWidget *ui;
    QVBoxLayout* vBox;

private slots:
    void updatePreviews(QList<ProductPreview> productPreviews);

};

#endif // CATALOGUEWIDGET_H
