#include <vector>

#include "./contactGetAllList.h"
#include "./contactGetAlllListAbstract.h"

#include "../../domain/contact.h"

ContactGetAllList::ContactGetAllList(ContactGetAllListAbstract *repository)
{
    this->repository = repository;
}
std::vector<Contact> ContactGetAllList::init()
{
    return repository->getAllList();
}