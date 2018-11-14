#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "src/statemachine.hpp"
#include "log.h"

namespace Luna {

    struct AppData
    {
        StateMachine machine;
    };

    typedef std::shared_ptr<AppData> AppDataRef;

    class Application
    {
    public:
        Application();
        ~Application();

    private:
        bool m_isRunning;
        AppDataRef m_data = std::make_shared<AppData>();

        void Run();
    };

}


#endif // APPLICATION_HPP
