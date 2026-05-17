#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include <QWidget>
#include <rep_user_replica.h>

namespace Ui {
class OrderWidget;
}

class OrderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderWidget(Order order, QWidget *parent = nullptr);
    ~OrderWidget();

private:
    Ui::OrderWidget *ui;
};

#endif // ORDERWIDGET_H
