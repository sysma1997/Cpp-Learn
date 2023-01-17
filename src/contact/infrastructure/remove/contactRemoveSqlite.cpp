#include <string>
#include <sqlite3.h>

#include "./contactRemoveSqlite.h"

ContactRemoveSqlite::ContactRemoveSqlite(sqlite3 *db)
{
    this->db = db;
}
void ContactRemoveSqlite::remove(int id)
{
    sqlite3_stmt *stmt;

    std::string query =
        "DELETE FROM Contacts WHERE id = ?";
    int fail = sqlite3_prepare_v2(db, query.c_str(), query.length(), &stmt, nullptr);
    if (fail != SQLITE_OK)
    {
        std::string errorMessage(sqlite3_errmsg(db));

        throw "SQLITE Error: to remove contact: " + errorMessage;
    }

    sqlite3_bind_int(stmt, 1, id);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}