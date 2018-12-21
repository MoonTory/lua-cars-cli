#include "loginstate.hpp"
#include "mainwindowstate.h"
#include <QString>
#include <QMessageBox>

namespace Luna {

    LoginState::LoginState(AppDataRef _data)
      :m_data( _data )
    {
        this->m_dialog = new LoginDialog();
        QObject::connect(this->m_dialog->loginBtn(), &QPushButton::clicked, [=](){ this->LoginEvent(); });
    }

    LoginState::~LoginState()
    {
        this->m_dialog->close();
        delete m_dialog;
        LUNA_WARN("Login State Deleted");
    }

    void LoginState::Init()
    {
        this->m_dialog->show();
        LUNA_INFO("Initialized Login State");
    }

    void LoginState::LoginEvent()
    {
        if(!this->m_data->eventHandler->Login(this->m_dialog->userEdit()->text(), this->m_dialog->passEdit()->text()))
        {
            QMessageBox::information(this->m_dialog, "Error!", "Username/Password is incorrect!");
        } else {
            this->m_data->machine->AddState(StateRef( new MainWindowState( m_data ) ), true);
            this->m_data->machine->Update();
        }
    }

}
