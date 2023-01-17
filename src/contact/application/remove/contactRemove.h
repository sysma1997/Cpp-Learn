#pragma once

#include "./contactRemoveAbstract.h"

class ContactRemove
{
private:
    ContactRemoveAbstract *repository;

public:
    ContactRemove(ContactRemoveAbstract *repository);

    void init(int id);
};