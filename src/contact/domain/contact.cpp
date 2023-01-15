#include "contact.h"

#include <string>
#include <json/json.h>

Contact::Contact()
{
    id = 0;
    name = "";
    email = "";
    phone = "";
}
Contact::Contact(long id, std::string name, std::string email, std::string phone)
{
    this->id = id;
    this->name = name;
    this->email = email;
    this->phone = phone;
}
long Contact::getId()
{
    return id;
}
std::string Contact::getName()
{
    return name;
}
std::string Contact::getEmail()
{
    return email;
}
std::string Contact::getPhone()
{
    return phone;
}

Json::Value Contact::toJSON()
{
    Json::Value::Int64 _id(id);

    Json::Value json;
    json["id"] = _id;
    json["name"] = name;
    json["email"] = email;
    json["phone"] = phone;

    return json;
}
std::string Contact::toString()
{
    Json::Value json = toJSON();

    return Json::FastWriter().write(json);
}