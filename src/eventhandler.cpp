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
            qDebug() << _username << _password;
            delete user;
            return true;
        } else {
            LUNA_ERROR("Login Unsuccessful");
            qDebug() << _username << _password;
            delete user;
            return false;
        }
    }

    User *EventHandler::user() const
    {
        return m_user;
    }

}
