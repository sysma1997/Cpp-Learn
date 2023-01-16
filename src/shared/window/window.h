#pragma once

#include <sqlite3.h>

#include "./ui/ui.h"

class Window
{
    sqlite3 *db;

public:
    Window(sqlite3 *db);

    void init(UI *ui);
};
