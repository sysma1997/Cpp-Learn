#pragma once

#include <iostream>
#include <string>
#include <json/json.h>

class Contact
{
    long id;
    std::string name;
    std::string email;
    std::string phone;

public:
    Contact();
    Contact(long id, std::string name, std::string email, std::string phone);

    long getId();
    std::string getName();
    std::string getEmail();
    std::string getPhone();

    Json::Value toJSON();
    std::string toString();
};