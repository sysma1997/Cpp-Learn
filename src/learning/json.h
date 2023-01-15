#pragma once

#include <fstream>
#include <iostream>
#include <json/json.h>

using namespace std;

void initJson()
{
    ifstream ifs("../src/learning/alice.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj); // reader can also read strings
    cout << "Book: " << obj["book"].asString() << endl;
    cout << "Year: " << obj["year"].asUInt() << endl;
    const Json::Value &characters = obj["characters"]; // array of characters
    for (int i = 0; i < characters.size(); i++)
    {
        cout << "    name: " << characters[i]["name"].asString();
        cout << " chapter: " << characters[i]["chapter"].asUInt();
        cout << endl;
    }

    obj["level"] = "Doom Eternal";
    cout << "Show level: " << obj["level"].asString() << endl;

    // print all json
    cout << obj << endl;
}