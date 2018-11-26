#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QApplication>
#include "src/statemachine.hpp"
#include "log.h"

namespace Luna {

    struct AppData
    {
        StateMachine machine;
    };

    typedef std::shared_ptr<AppData> AppDataRef;

    class Application : public QApplication
    {
        Q_OBJECT
    public:
        Application(int argc, char* argv[]);
        ~Application();

    private:
        bool m_isRunning;
        AppDataRef m_data = std::make_shared<AppData>();

        void Run();
    };

} // namespace luna

#endif // APPLICATION_HPP
