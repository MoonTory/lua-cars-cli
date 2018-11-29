#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QApplication>
#include "appdata.h"
#include "log.h"
#include <memory>

namespace Luna {

    class Application : public QApplication
    {
        Q_OBJECT
    public:
        Application(int argc, char* argv[]);
        ~Application();

    private:
        bool m_isRunning;
        // Shared pointer of AppData
        AppDataRef m_data = std::make_shared<AppData>();

        void Run();
    };

} // namespace luna

#endif // APPLICATION_HPP
