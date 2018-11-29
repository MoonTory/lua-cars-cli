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
        std::string _user = _username.toStdString();
        std::string _pass = _password.toStdString();

        User *user = this->m_db->FindUser(_user, _pass);
        if (user != nullptr)
        {
            this->m_user = this->m_db->FindUser(_user, _pass);
            LUNA_INFO("Login Handler");
            LUNA_TRACE("Login Attempt -> User: {0} Pass: {1}", _user, _pass);
            delete user;
            return true;
        } else {
            LUNA_ERROR("Login Unsuccessful");
            LUNA_TRACE("Login Attempt -> User: \"{0}\" Pass: \"{1}\"", _user, _pass);
            delete user;
            return false;
        }
    }

    User *EventHandler::user() const
    {
        return m_user;
    }

}
