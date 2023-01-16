#pragma once

#include <vector>
#include <sqlite3.h>

#include "../../domain/contact.h"
#include "../../application/getAllList/contactGetAlllListAbstract.h"

class ContactGetAllListSqlite : public ContactGetAllListAbstract
{
private:
    sqlite3 *db;

public:
    ContactGetAllListSqlite(sqlite3 *db);

    std::vector<Contact> getAllList();
};