#include "eventhandler.h"
#include "log.h"

#include <QDebug>

namespace Luna {

    EventHandler::EventHandler(QObject *parent)
        :QObject(parent)
    {
        this->m_db = new Database();
    }

    bool EventHandler::LoginHandle(const QString &_username, const QString &_password)
    {
		// Converting QString to STD Strings
        std::string _user = _username.toStdString();
        std::string _pass = _password.toStdString();

		// Creating a new user with the results of our DB query.
        User *user = this->m_db->FindUser(_user, _pass);
        if (user != nullptr) {
            this->m_user = this->m_db->FindUser(_user, _pass); // Set Event Handler User
            LUNA_INFO("Login Handler");
            LUNA_TRACE("Login Attempt -> User: {0} Pass: {1}", _user, _pass);
            delete user; // Free memory
            return true;
        } else {
            LUNA_ERROR("Login Unsuccessful");
            LUNA_TRACE("Login Attempt -> User: \"{0}\" Pass: \"{1}\"", _user, _pass);
            delete user;
            return false;
        }
    }

	bool EventHandler::Login(const QString & _username, const QString & _password)
	{
		this->m_user = this->m_db->query_users(_username, _password);
		if (this->m_user != nullptr)
		{
			LUNA_INFO("Login Handler");
			LUNA_TRACE("Login Attempt -> User: {0} Pass: {1}", _username.toStdString(), _password.toStdString());
			// delete user; // Free memory
			return true;
		} else {
			LUNA_ERROR("Login Unsuccessful");
			LUNA_TRACE("Login Attempt -> User: \"{0}\" Pass: \"{1}\"", _username.toStdString(), _password.toStdString());
			// delete user;
			return false;
		}
	}

    User *EventHandler::user() const
    {
        return m_user;
    }

}
