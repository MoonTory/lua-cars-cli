#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QString>

#include "Models/user.h"
#include "DbManager.h"

namespace Luna {

    class EventHandler
    {
    public:
        explicit EventHandler();

        // Event Handlers
		bool LoginHandle(const QString &_username, const QString &_password);

        // Getter Methods
        User *user() const;

    private:
		User *m_user;
		DbManager *m_db;
    };

}

#endif // EVENTHANDLER_H
