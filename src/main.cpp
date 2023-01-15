#include <iostream>
#include <string>

#include "./contact/domain/contact.h"
#include "./contact/application/create/contactCreate.h"
#include "./contact/infrastructure/create/contactCreateList.h"

int main(int, char **)
{
    ContactCreateList repository;
    ContactCreate create(&repository);

    try
    {
        create.init(Contact(1, "Sebastian Moreno Acero", "sysma1997@gmail.com", "315 357 7794"));
        create.init(Contact(2, "Stiven Moreno Acero", "siventma@gmail.com", "316 528 3060"));
    }
    catch (std::string message)
    {
        std::cout << message << std::endl;

        return 0;
    }

    repository.printAll();

    return 0;
}