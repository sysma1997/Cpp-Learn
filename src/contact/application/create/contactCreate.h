#pragma once

#include "../../domain/contact.h"
#include "./contactCreateAbstract.h"

class ContactCreate
{
private:
    ContactCreateAbstract *repository;

public:
    ContactCreate(ContactCreateAbstract *repository);

    void init(Contact contact);
};