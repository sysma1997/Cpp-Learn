#include <iostream>
#include <sqlite3.h>

void initSQLite3()
{
    sqlite3 *db;
    char *errorMessage = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc)
    {
        std::cout << "Can't open database: " << sqlite3_errmsg(db) << std::endl;

        return;
    }

    std::cout << "Open database successfully" << std::endl;

    sqlite3_close(db);

    return;
}