#include <string>

#include "../../domain/contact.h"
#include "./contactEditAbstract.h"
#include "./contactEdit.h"

ContactEdit::ContactEdit(ContactEditAbstract *repository)
{
    this->repository = repository;
}
void ContactEdit::init(Contact contact)
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

    repository->edit(contact);
}