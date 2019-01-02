#include "user.h"

namespace Luna {

    User::User(const std::string &_username, const std::string &_password, UserLevel _level)
    {
        this->setUsername(_username);
        this->setPassword(_password);
        this->setLevel(_level);
    }

    User::~User() {  }

    std::string User::username() const
    {
        return m_username;
    }

    void User::setUsername(const std::string &username)
    {
        m_username = username;
    }

    std::string User::password() const
    {
        return m_password;
    }

    void User::setPassword(const std::string &password)
    {
        m_password = password;
    }

    std::string User::level() const
    {
		switch (this->m_level) {
		case 0:
			return "ADMIN";
			break;
		case 1:
			return "CLIENT";
			break;
		case 2:
			return "DEV";
			break;
		default:
			break;
		}
    }

    void User::setLevel(const UserLevel &level)
    {
        m_level = level;
    }

}
