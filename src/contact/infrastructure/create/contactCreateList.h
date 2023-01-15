#pragma once

#include <vector>

#include "../../domain/contact.h"
#include "../../application/create/contactCreateAbstract.h"

class ContactCreateList : public ContactCreateAbstract
{
private:
    std::vector<Contact> contacts;

public:
    void create(Contact contact);

    void printAll();
};