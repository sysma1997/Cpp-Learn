#include <iostream>
#include <string>

#include "./contactCreateList.h"

#include "../../domain/contact.h"

void ContactCreateList::create(Contact contact)
{
    contacts.push_back(contact);
}
void ContactCreateList::printAll()
{
    for (int i = 0; i < contacts.size(); i++)
    {
        std::cout << contacts.at(i).toString();
    }
}