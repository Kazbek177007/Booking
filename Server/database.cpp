#include "database.h"
#include <QSqlError>
#include <QSqlQuery>

Database& Database::instance()
{
    static Database instance;
    return instance;
}

bool Database::open(QString filepath)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filepath);
    if(!db.open())
    {
        qWarning() << "Database is not opened";
        return false;
    }
    createTables();
    qDebug() << "Database is opened";
    return true;
}

bool Database::isOpened() const
{
    return db.isOpen();
}

int Database::addProduct(const Product& product)
{
    QSqlQuery query(db);
    query.prepare ("INSERT INTO products (name, icon, price)"
                  "VALUES (?, ?, ?)");

    query.bindValue(0, product.preview().name());
    query.bindValue(1, product.preview().icon());
    query.bindValue(2, product.preview().price());

    if(!query.exec())
    {
        qWarning() << "addProduct() hasn't started";
        return -1;
    }
    return query.lastInsertId().toInt();
}

void Database::updateProduct(const Product& product)
{
    QSqlQuery query(db);
    query.prepare("UPDATE products SET name = ?, icon = ?, price = ?, isPublished = ?  WHERE id = ?");

    query.bindValue(0, product.preview().name());
    query.bindValue(1, product.preview().icon());
    query.bindValue(2, product.preview().price());
    query.bindValue(3, product.isPublished());
    query.bindValue(4, product.preview().id());


    if(!query.exec()) qWarning() << "updateProduct() hasn't started" << query.lastError().text();
}

void Database::removeProduct(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM products WHERE id = ?");

    query.bindValue(0, id);

    if(!query.exec()) qWarning() << "Ошибка удаления:" << query.lastError().text();
}

void Database::createTables()
{
    QSqlQuery query(db);
    if(!query.exec
         ("CREATE TABLE IF NOT EXISTS products ("
          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
          "name TEXT NOT NULL,"
          "icon BLOB,"
          "price REAL NOT NULL DEFAULT 0,"
          "isPublished INTEGER NOT NULL DEFAULT 0"))
        qWarning() << "Table products are not created";
    if(!query.exec("CREATE TABLE IF NOT EXISTS orders ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "userId TEXT NOT NULL,"
                    "items BLOB NOT NULL,"
                    "dateTime TEXT NOT NULL"))
        qWarning() << "Table orders are not created";
}