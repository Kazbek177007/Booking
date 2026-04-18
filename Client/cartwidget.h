#ifndef CARTWIDGET_H
#define CARTWIDGET_H

#include <QWidget>

namespace Ui {
class CartWidget;
}

class CartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CartWidget(QWidget *parent = nullptr);
    ~CartWidget();

private:
    Ui::CartWidget *ui;

private slots:
    void updateCart();
};

#endif // CARTWIDGET_H
