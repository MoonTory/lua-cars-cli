#include "mainwindowstate.h"

namespace Luna {

    MainWindowState::MainWindowState( AppDataRef _data )
        :m_data( _data )
    {
        this->m_window = new MainWindow();
    }

    MainWindowState::~MainWindowState()
    {
        LUNA_WARN("Main Window State deleted");
    }

    void MainWindowState::Init()
    {
        this->m_window->show();
        LUNA_INFO("Initialized Main Window State");
    }

}
