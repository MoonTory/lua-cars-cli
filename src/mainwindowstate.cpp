#include "mainwindowstate.h"

namespace Luna {

    MainWindowState::MainWindowState( AppDataRef _data )
        :m_data( _data )
    {
        this->m_window = new MainWindow();
        this->m_window->labelUser()->setText(QString::fromStdString(this->m_data->eventHandler->user()->username()));
        switch (this->m_data->eventHandler->user()->level()) {
        case 0:
            this->m_window->labelLevel()->setText("ADMIN");
            break;
        case 1:
            this->m_window->labelLevel()->setText("CLIENT");
            break;
        case 2:
            this->m_window->labelLevel()->setText("DEV");
            break;
        default:
            break;
        }
        QObject::connect(this->m_window->aboutAction(), SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));
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
