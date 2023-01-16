#include <iostream>
#include <string>
#include <sqlite3.h>

#include "./shared/global.h"
#include "./shared/database/database.h"
#include "./shared/window/window.h"
#include "./shared/window/ui/ui.h"

#include "./contact/domain/contact.h"
#include "./contact/application/getAllList/contactGetAllList.h"
#include "./contact/infrastructure/getAllList/contactGetAllListSqlite.h"

int main(int, char **)
{
    char *errorMessage = 0;
    int rc;

    rc = sqlite3_open("contacts.db", &Global::db);

    if (rc)
    {
        std::cout << "Can't open database: " << sqlite3_errmsg(Global::db) << std::endl;

        return 0;
    }

    try
    {
        createTables(Global::db);
    }
    catch (std::string error)
    {
        std::cout << error << std::endl;

        sqlite3_close(Global::db);

        return 0;
    }

    ContactGetAllListSqlite repository(Global::db);
    ContactGetAllList getAllList(&repository);

    try
    {
        Global::contacts = getAllList.init();
    }
    catch (std::string error)
    {
        std::cout << error << std::endl;
    }

    Window window(Global::db);
    UI ui;

    try
    {
        window.init(&ui);
    }
    catch (std::string error)
    {
        std::cout << error << std::endl;
    }

    sqlite3_close(Global::db);

    return 0;
}