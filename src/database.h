#ifndef DATABASE_H
#define DATABASE_H

#include "Models/user.h"
#include "Models/client.h"
#include "Models/address.h"
#include <QtSql>
#include <QString>

namespace Luna {

    class Database
    {
    public:
        Database();
		~Database();

        // Database Query Methods
        void InsertUser(const User &_user);
        User *FindUser(const std::string &_username, const std::string &_password);
		User *query_users(const QString &_username, const QString &_password);
	private:
		QSqlDatabase m_db;
    };

}

#endif // DATABASE_H
