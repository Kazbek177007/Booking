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
    ui->stackedWidget->addWidget(catalogue);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->catalogueButton, &QPushButton::clicked, this, &MainWindow::showCatalogue);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::showLoginWidget);
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

void MainWindow::showLoginWidget()
{
    LoginWidget* loginw = new LoginWidget(this);
    connect(loginw, &QDialog::accepted, [loginw, this](){
        Client::instance()->login(loginw->phoneNumber());
        cart = new CartWidget;
        userProfile = new UserProfileWidget;
        ui->stackedWidget->addWidget(cart);
        ui->stackedWidget->addWidget(userProfile);
        QPushButton* cartButton = new QPushButton("Cart");
        QPushButton* userProfileButton = new QPushButton("User Profile");
        ui->horizontalLayout->addWidget(cartButton);
        ui->horizontalLayout->addWidget(userProfileButton);
        connect(cartButton, &QPushButton::clicked, this, &MainWindow::showCart);
        connect(userProfileButton, &QPushButton::clicked, this, &MainWindow::showUserProfile);
        ui->loginButton->hide();
    });
    loginw->open();

}
