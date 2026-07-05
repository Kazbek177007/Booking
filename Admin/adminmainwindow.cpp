#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"

AdminMainWindow::AdminMainWindow(QWidget* parent)
    : QWidget(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);

    productsManager = new ProductsManagerWidget;
    ui->stackedWidget->addWidget(productsManager);
    ui->stackedWidget->setCurrentWidget(productsManager);

    connect(ui->productsButton, &QPushButton::clicked, this, &AdminMainWindow::showProductsManager);
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

void AdminMainWindow::showProductsManager()
{
    ui->stackedWidget->setCurrentWidget(productsManager);
}
