#include "eventhandler.h"
#include "log.h"

#include <QDebug>

namespace Luna {

    EventHandler::EventHandler()
    {
        this->m_db = new DbManager(QString("./db/data.db"));
    }

	bool EventHandler::LoginHandle(const QString & _username, const QString & _password)
	{
		this->m_user = this->m_db->auth_user(_username, _password);
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
