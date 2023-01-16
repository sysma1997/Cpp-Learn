#include <string>
#include <sqlite3.h>

#include "./contactCreateSqlite.h"

#include "../../domain/contact.h"

ContactCreateSqlite::ContactCreateSqlite(sqlite3 *db)
{
    this->db = db;
}
void ContactCreateSqlite::create(Contact contact)
{
    sqlite3_stmt *stmt;

    std::string query =
        "INSERT INTO Contacts(name, email, phone) VALUES(?, ?, ?)";
    int fail = sqlite3_prepare_v2(db, query.c_str(), query.length(), &stmt, nullptr);
    if (fail != SQLITE_OK)
    {
        std::string errorMessage(sqlite3_errmsg(db));

        throw "SQLITE Error: to insert contact: " + errorMessage;
    }

    sqlite3_bind_text(stmt, 1, contact.getName().c_str(), contact.getName().length(), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, contact.getEmail().c_str(), contact.getEmail().length(), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, contact.getPhone().c_str(), contact.getPhone().length(), SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}