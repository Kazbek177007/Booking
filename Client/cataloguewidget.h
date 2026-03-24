#ifndef CATALOGUEWIDGET_H
#define CATALOGUEWIDGET_H

#include <QScrollArea>

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
};

#endif // CATALOGUEWIDGET_H
