#include <string>
#include <vector>
#include <sqlite3.h>

#include "./global.h"

#include "../contact/domain/contact.h"

sqlite3 *Global::db;
std::vector<Contact> Global::contacts;

int Global::windowWidth = 1024;
int Global::windowHeight = 640;

char Global::search[100] = "";

bool Global::showImGuiDemo = false;

Contact Global::contact = Contact();
bool Global::showScreenContact = false;
bool Global::editContact = false;
char Global::contactName[100] = "";
char Global::contactEmail[100] = "";
char Global::contactPhone[20] = "";
std::string Global::contactMessage;