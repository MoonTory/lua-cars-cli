#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QString>

#include "models/user.h"
#include "database.h"

namespace Luna {

    class EventHandler : public QObject
    {
        Q_OBJECT
    public:
        explicit EventHandler(QObject *parent = nullptr);

        bool LoginHandle(const QString &_username, const QString &_password);

        User *user() const;

    private:
        User *m_user;
        Database *m_db;
    };

}

#endif // EVENTHANDLER_H
