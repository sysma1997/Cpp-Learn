#include <string>

#include "../../domain/contact.h"
#include "./contactCreateAbstract.h"
#include "./contactCreate.h"

ContactCreate::ContactCreate(ContactCreateAbstract *repository)
{
    this->repository = repository;
}
void ContactCreate::init(Contact contact)
{
    if (contact.getId() == 0 ||
        contact.getName() == "")
    {
        std::string message;

        if (contact.getId() == 0)
            message += "Id not valid.\n";
        if (contact.getName() == "")
            message += "Name not valid.";

        throw message;
    }

    repository->create(contact);
}