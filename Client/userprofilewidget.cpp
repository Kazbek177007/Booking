#include "userprofilewidget.h"
#include "ui_userprofilewidget.h"
#include "client.h"
#include "orderwidget.h"

UserProfileWidget::UserProfileWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserProfileWidget)
{
    ui->setupUi(this);
    connect(Client::instance()->orderHistory.get(), &OrderHistoryReplica::ordersChanged, [this](QList<Order> orders)
            {
                while (ui->toolBox->count() > 0)
                {
                    ui->toolBox->removeItem(0);
                }

                for (int i = 0; i < orders.size(); i++)
                {
                    OrderWidget* orderWidget = new OrderWidget(orders[i]);
                    ui->toolBox->addItem(orderWidget, QString::number(i));
                }
            });
}

UserProfileWidget::~UserProfileWidget()
{
    delete ui;
}
