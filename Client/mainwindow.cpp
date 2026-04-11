#include "client.h"
#include "loginwidget.h"
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
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->catalogueButton, &QPushButton::clicked, this, &MainWindow::showCatalogue);
    connect(ui->cartButton, &QPushButton::clicked, this, &MainWindow::showCart);
    connect(ui->userProfileButton, &QPushButton::clicked, this, &MainWindow::showUserProfile);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::showLogin);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showCatalogue()
{
    ui->stackedWidget->setCurrentWidget(catalogue);
    qDebug() << catalogue->size();
}

void MainWindow::showCart()
{
    ui->stackedWidget->setCurrentWidget(cart);
}

void MainWindow::showUserProfile()
{
    ui->stackedWidget->setCurrentWidget(userProfile);
}

void MainWindow::showLogin()
{
    LoginWidget* loginw = new LoginWidget(this);
    connect(loginw, &QDialog::accepted, [loginw](){
        Client::instance()->login(loginw->phoneNumber());
    });
    loginw->open();
}
