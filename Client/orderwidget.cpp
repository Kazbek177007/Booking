#include "client.h"
#include "orderwidget.h"
#include "ui_orderwidget.h"

#include <qstandarditemmodel.h>

OrderWidget::OrderWidget(Order order, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrderWidget)
{
    ui->setupUi(this);
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setColumnCount(3);
    auto items = order.items();
    auto keys = items.keys();
    for (int i = 0; i < items.count(); i++)
    {
        auto id = keys.at(i);
        std::optional<ProductPreview> pp = Client::instance()->productPreview(id);
        if(!pp) continue;
        model->insertRow(i);
        model->setData(model->index(i,0), pp.value().name());
        model->setData(model->index(i,1), items.value(id)); qDebug() << items.value(id); //qty
        model->setData(model->index(i,2), pp.value().price() * items.value(id)); qDebug() << pp.value().price() * items.value(id); qDebug() << pp.value().price(); //sum
    }
    ui->tableView->setModel(model);


}

OrderWidget::~OrderWidget()
{
    delete ui;
}
