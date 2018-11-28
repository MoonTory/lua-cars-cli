#ifndef DATABASE_H
#define DATABASE_H

#include "models/user.h"
#include "models/client.h"
#include "models/adress.h"

namespace Luna {

    class Database
    {
    public:
        Database();

        void InsertUser(const User &_user);
        User *FindUser(const std::string &_username, const std::string &_password);
    };

}

#endif // DATABASE_H
