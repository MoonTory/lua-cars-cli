#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QString>

namespace Luna {

    class EventHandler : public QObject
    {
        Q_OBJECT
    public:
        explicit EventHandler(QObject *parent = nullptr);

        void loginHandle(const QString &_username, const QString &_password);
    };

}

#endif // EVENTHANDLER_H
