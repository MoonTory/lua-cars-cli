#include "database.h"
#include "log.h"
#include <fstream>
#include <sstream>

namespace Luna {

	Database::Database() {  }

	Database::~Database() { this->m_db.close(); }

    void Database::InsertUser(const User &_user)
    {
        std::fstream file;
        file.open("Users.txt", std::ios::in | std::ios::out | std::ios::app);

        if(!file.is_open())
        {
            LUNA_ERROR("Error while opening the file.");
        }

        file << _user.username() << ";" << _user.password() << ";" << _user.level() << std::endl;

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
        std::string tempLevel;
        std::string lineQuery;

        // Query "Users.txt" for User & return the found user
        while(std::getline(file, lineQuery))
        {
            std::stringstream ss(lineQuery);
            std::getline(ss, username, ';');
            std::getline(ss, password, ';');
            std::getline(ss, tempLevel, ';');
            int level = stoi(tempLevel); // Converting string into an "Int"

            if(_username == username && _password == password) // Validating User query
            {
                User *payload = new User();
                payload->setUsername(username);
                payload->setPassword(password);
                switch (level) { // Verifying User level, and setting payload accordingly
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
				file.close();
            } else { continue; }
        }

        file.close();
        return nullptr; // Return a nullptr if no User was found in the query.
    }

	User *Database::query_users(const QString & _username, const QString & _password)
	{
		this->m_db = QSqlDatabase::addDatabase("QSQLITE");
		this->m_db.setDatabaseName("./db/data.db");

		if (!this->m_db.open())
		{
			LUNA_ERROR("Error loading users.db File, please verify '/db' directory...");
			this->m_db.lastError();
			return nullptr;
		}
		else {
			LUNA_INFO("Connected to 'Users' db...");
			QSqlQuery query;
			while (query.exec("select username, password, level from Users where username='" + _username + "' and password='" + _password + "'"))
			{
				if (query.next())
				{
					User *payload = new User();
					QString _user = query.value(0).toString();
					QString _pass = query.value(1).toString();
					QString _level = query.value(2).toString();

					payload->setUsername(_user.toStdString());
					payload->setPassword(_pass.toStdString());

					switch (_level.toInt()) { // Verifying User level, and setting payload accordingly
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

					this->m_db.close();
					this->m_db = QSqlDatabase();
					this->m_db.removeDatabase(QSqlDatabase::defaultConnection);
					return payload;
					delete payload;

				} else {
					this->m_db.close();
					this->m_db = QSqlDatabase();
					this->m_db.removeDatabase(QSqlDatabase::defaultConnection);
					return nullptr;
				}
			}
		}
	}

}

