#pragma once
#include <QList>
#include <QString>
#include <QSqlDatabase>
#include "rep_admin_source.h"
#include "rep_user_source.h"

class Database
{
public:
    static Database& instance();
    bool open(QString filepath = "Booking.db");
    bool isOpened() const;
    QList<Product> loadProducts() const;
    void addProduct(const Product& product);
    void updateProduct(const Product& product);
    void removeProduct(int id);
    QList<Order> loadOrders() const;
    void addOrder(const Order& order);
private:
    Database() = default;
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;
    QSqlDatabase db;
    void createTables();
};
