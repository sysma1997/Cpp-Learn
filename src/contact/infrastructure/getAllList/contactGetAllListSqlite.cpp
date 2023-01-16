#include <string>
#include <vector>

#include "./contactGetAllListSqlite.h"

#include "../../domain/contact.h"

ContactGetAllListSqlite::ContactGetAllListSqlite(sqlite3 *db)
{
    this->db = db;
}
std::vector<Contact> ContactGetAllListSqlite::getAllList()
{
    sqlite3_stmt *stmt;

    std::string query =
        "SELECT * FROM Contacts";
    int fail = sqlite3_prepare_v2(db, query.c_str(), query.length(), &stmt, nullptr);
    if (fail != SQLITE_OK)
    {
        std::string errorMessage(sqlite3_errmsg(db));

        throw "SQLITE Error: to select the Contacts: " + errorMessage;
    }

    std::vector<Contact> contacts;
    int row = 0;
    while ((row = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        std::string name = "";
        std::string email = "";
        std::string phone = "";

        if (sqlite3_column_type(stmt, 1) != SQLITE_NULL)
            name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        if (sqlite3_column_type(stmt, 2) != SQLITE_NULL)
            email = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
            phone = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));

        Contact contact{id, name, email, phone};

        contacts.push_back(contact);
    }

    sqlite3_finalize(stmt);

    return contacts;
}