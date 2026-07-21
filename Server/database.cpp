#include "database.h"

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