#include <iostream>
#include <string>
#include <sqlite3.h>

#include "./shared/global.h"
#include "./shared/database/database.h"
#include "./shared/window/window.h"
#include "./shared/window/ui/ui.h"

int main(int, char **)
{
    sqlite3 *db;
    char *errorMessage = 0;
    int rc;

    rc = sqlite3_open("contacts.db", &db);

    if (rc)
    {
        std::cout << "Can't open database: " << sqlite3_errmsg(db) << std::endl;

        return 0;
    }

    try
    {
        createTables(db);
    }
    catch (std::string error)
    {
        std::cout << error << std::endl;

        sqlite3_close(db);

        return 0;
    }

    Window window(db);
    UI ui;

    try
    {
        window.init(&ui);
    }
    catch (std::string error)
    {
        std::cout << error << std::endl;
    }

    sqlite3_close(db);

    return 0;
}