#pragma once

#include "../../domain/contact.h"
#include "./contactEditAbstract.h"

class ContactEdit
{
private:
    ContactEditAbstract *repository;

public:
    ContactEdit(ContactEditAbstract *repository);

    void init(Contact contact);
};