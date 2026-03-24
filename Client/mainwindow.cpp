#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    catalogue = new CatalogueWidget;
    cart = new CartWidget;
    userProfile = new UserProfileWidget;
    ui->stackedWidget->addWidget(catalogue);
    ui->stackedWidget->addWidget(cart);
    ui->stackedWidget->addWidget(userProfile);
    connect(ui->catalogueButton, &QPushButton::clicked, this, &MainWindow::showCatalogue);
    connect(ui->cartButton, &QPushButton::clicked, this, &MainWindow::showCart);
    connect(ui->userProfileButton, &QPushButton::clicked, this, &MainWindow::showUserProfile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showCatalogue()
{
    ui->stackedWidget->setCurrentWidget(catalogue);
}

void MainWindow::showCart()
{
    ui->stackedWidget->setCurrentWidget(cart);
}

void MainWindow::showUserProfile()
{
    ui->stackedWidget->setCurrentWidget(userProfile);
}
