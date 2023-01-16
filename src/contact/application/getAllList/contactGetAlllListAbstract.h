#pragma once

#include <sqlite3.h>
#include <vector>

#include "../../domain/contact.h"

class ContactGetAllListAbstract
{
public:
    ContactGetAllListAbstract() {}
    virtual std::vector<Contact> getAllList() = 0;
};