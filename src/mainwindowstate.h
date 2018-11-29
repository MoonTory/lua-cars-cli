#ifndef MAINWINDOWSTATE_H
#define MAINWINDOWSTATE_H

#include "state.hpp"
#include "application.hpp"
#include "MainWindow/mainwindow.h"

namespace Luna {

    class MainWindowState : public State
    {
    public:
        MainWindowState( AppDataRef _data );
        ~MainWindowState() override;

        // State method override
        void Init() override;
    private:
        AppDataRef m_data;
        MainWindow *m_window;
    };

} // namespace Luna

#endif // MAINWINDOWSTATE_H
