#pragma once

#include "../../domain/contact.h"

class ContactEditAbstract
{
public:
    ContactEditAbstract() {}
    virtual void edit(Contact contact) = 0;
};