#ifndef DATABASE_H
#define DATABASE_H

#include "Models/user.h"
#include "Models/client.h"
#include "Models/address.h"

namespace Luna {

    class Database
    {
    public:
        Database();


        // Database Query Methods
        void InsertUser(const User &_user);
        User *FindUser(const std::string &_username, const std::string &_password);
    };

}

#endif // DATABASE_H
