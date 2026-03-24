#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStackedWidget>
#include <QWidget>
#include "cataloguewidget.h"
#include "cartwidget.h"
#include "userprofilewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void showCatalogue();
    void showCart();
    void showUserProfile();

private:
    Ui::MainWindow* ui;
    CatalogueWidget* catalogue;
    CartWidget* cart;
    UserProfileWidget* userProfile;
};

#endif // MAINWINDOW_H
