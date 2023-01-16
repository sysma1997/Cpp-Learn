#pragma once

#include <vector>

#include "../../domain/contact.h"
#include "./contactGetAlllListAbstract.h"

class ContactGetAllList
{
private:
    ContactGetAllListAbstract *repository;

public:
    ContactGetAllList(ContactGetAllListAbstract *repository);

    std::vector<Contact> init();
};