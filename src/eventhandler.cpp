#include "eventhandler.h"
#include "log.h"

#include <QDebug>

namespace Luna {

    EventHandler::EventHandler(QObject *parent)
        :QObject(parent)
    {

    }

    void EventHandler::loginHandle(const QString &_username, const QString &_password)
    {
        LUNA_INFO("Login Handler");
        qDebug() << _username << _password;
    }

}
