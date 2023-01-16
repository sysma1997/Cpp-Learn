#include <string>
#include <sqlite3.h>

#include "./database.h"

void createTables(sqlite3 *db)
{
    char *errorMessage = 0;
    std::string query =
        "CREATE TABLE IF NOT EXISTS Contacts("
        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
        "name TEXT NOT NULL, "
        "email TEXT NULL, "
        "phone TEXT NULL);";

    int success = sqlite3_exec(db, query.c_str(), NULL, 0, &errorMessage);
    if (success != SQLITE_OK)
        throw "SQLITE Error: " + std::string(errorMessage);
}