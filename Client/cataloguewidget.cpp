#include "cataloguewidget.h"
#include "ui_cataloguewidget.h"

CatalogueWidget::CatalogueWidget(QWidget *parent)
    : QScrollArea(parent)
    , ui(new Ui::CatalogueWidget)
{
    ui->setupUi(this);
}

CatalogueWidget::~CatalogueWidget()
{
    delete ui;
}
