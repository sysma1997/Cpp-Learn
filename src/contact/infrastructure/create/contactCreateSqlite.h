#pragma once

#include <sqlite3.h>

#include "../../domain/contact.h"
#include "../../application/create/contactCreateAbstract.h"

class ContactCreateSqlite : public ContactCreateAbstract
{
private:
    sqlite3 *db;

public:
    ContactCreateSqlite(sqlite3 *db);

    void create(Contact contact);
};