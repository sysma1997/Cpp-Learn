#include <string>

#include "./contactRemove.h"
#include "./contactRemoveAbstract.h"

ContactRemove::ContactRemove(ContactRemoveAbstract *repository)
{
    this->repository = repository;
}
void ContactRemove::init(int id)
{
    if (id == 0)
    {
        throw "Id not valid.";
    }

    repository->remove(id);
}