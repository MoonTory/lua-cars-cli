#include "loginstate.hpp"
#include <QString>

namespace Luna {

    LoginState::LoginState(AppDataRef _data)
      :m_data( _data )
    {
        this->m_dialog = new LoginDialog();
        QObject::connect(this->m_dialog->loginBtn(), &QPushButton::clicked, [=](){ this->m_data->eventHandler->loginHandle(this->m_dialog->userEdit()->text(), this->m_dialog->passEdit()->text()); });
    }

    void LoginState::Init()
    {
        this->m_dialog->show();
        LUNA_INFO("Initialized Login State");
    }

}
