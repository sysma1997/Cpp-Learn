#pragma once

#include "../../domain/contact.h"

class ContactCreateAbstract
{
public:
    ContactCreateAbstract() {}
    virtual void create(Contact contact) = 0;
};