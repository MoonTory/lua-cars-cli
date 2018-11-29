#include "database.h"
#include <fstream>
#include <sstream>
#include "log.h"

namespace Luna {

    Database::Database() {  }

    void Database::InsertUser(const User &_user)
    {
        std::fstream file;
        file.open("Users.txt", std::ios::in | std::ios::out | std::ios::app);

        if(!file.is_open())
        {
            LUNA_ERROR("Error while opening the file.");
        }

        file << _user.username() << ";" << _user.password() << ";" << _user.level() << ";" << std::endl;

        file.flush();
        file.close();
    }

    User *Database::FindUser(const std::string &_username, const std::string &_password)
    {
        std::fstream file;
        file.open("Users.txt", std::ios::in);

        if(!file.is_open()) // Checking for file health
        {
            LUNA_ERROR("Error while opening the file.");
            return nullptr;
        }

        // Temp strings for file query
        std::string username;
        std::string password;
        std::string aux;
        std::string temp;

        // Query "Users.txt" for User & return the found user
        while(std::getline(file, temp))
        {
            std::stringstream ss(temp);
            std::getline(ss, username, ';');
            std::getline(ss, password, ';');
            std::getline(ss, aux, ';');
            int level = stoi(aux);

            if(_username == username && _password == password) // Validating User query
            {
                User *payload = new User();
                payload->setUsername(username);
                payload->setPassword(password);
                switch (level) {
                case 0:
                    payload->setLevel(UserLevel::USER_ADMIN);
                    break;
                case 1:
                    payload->setLevel(UserLevel::USER_CLIENT);
                    break;
                case 2:
                    payload->setLevel(UserLevel::USER_DEV);
                    break;
                }
                file.close();
                return payload; // Return found & validated User
                delete payload;
            } else { continue; }
        }

        file.close();
        return nullptr; // Return a nullptr is no User was found in the query.
    }

}

