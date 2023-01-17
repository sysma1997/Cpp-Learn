#pragma once

#include <sqlite3.h>

#include "../../domain/contact.h"
#include "../../application/edit/contactEditAbstract.h"

class ContactEditSqlite : public ContactEditAbstract
{
private:
    sqlite3 *db;

public:
    ContactEditSqlite(sqlite3 *db);

    void edit(Contact contact);
};