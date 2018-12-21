#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "appdata.h"
#include "log.h"
#include <QApplication>
#include <memory>

namespace Luna {

    class Application : public QApplication
    {
        Q_OBJECT
    public:
        Application(int argc, char* argv[]);
        ~Application();

    private:
        // Shared pointer of AppData
        AppDataRef m_data = std::make_shared<AppData>();

        void Run();
    };

} // namespace luna

#endif // APPLICATION_HPP
