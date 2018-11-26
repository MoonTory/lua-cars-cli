#include <iostream>
#include "src/application.hpp"

/*
 * TODO: File Manager
 * TODO: Read & Write to JSON files
 * TODO: Login State
 * TODO: Main Menu State
 * TODO: License
 */

int main(int argc, char *argv[])
{
    Luna::Application app(argc, argv);

    return app.exec();
}
