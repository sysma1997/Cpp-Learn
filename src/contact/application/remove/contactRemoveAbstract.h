#pragma once

class ContactRemoveAbstract
{
public:
    ContactRemoveAbstract() {}
    virtual void remove(int id) = 0;
};