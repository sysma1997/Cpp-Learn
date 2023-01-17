#pragma once

#include <sqlite3.h>

#include "../../application/remove/contactRemoveAbstract.h"

class ContactRemoveSqlite : public ContactRemoveAbstract
{
private:
    sqlite3 *db;

public:
    ContactRemoveSqlite(sqlite3 *db);

    void remove(int id);
};