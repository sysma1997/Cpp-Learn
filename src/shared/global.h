#pragma once

#include <vector>
#include <sqlite3.h>

#include "../contact/domain/contact.h"

class Global
{
public:
    static sqlite3 *db;
    static std::vector<Contact> contacts;

    static int windowWidth;
    static int windowHeight;

    static char search[100];

    static bool showImGuiDemo;

    static Contact contact;
    static bool showScreenContact;
};