#include <iostream>
#include "src/application.hpp"

/*
 * []TODO: Read & Write to JSON files
 * [x]TODO: Login State
 * []TODO: Main State
 * []TODO: Client CRUD
 * [x]TODO: Event Handler
 * []TODO: Data Manager
 * []TODO: License
 */

int main(int argc, char *argv[])
{
    Luna::Application app(argc, argv);
    return app.exec();
}
