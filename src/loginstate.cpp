#include "loginstate.hpp"
#include <iostream>

#include <nlohmann/json.hpp>

namespace Luna {

    LoginState::LoginState(AppDataRef _data)
      :m_data( _data )
    {

    }

    void LoginState::Init()
    {
        m_dialog.show();
        LUNA_WARN("Initialized Login State");
    }

}
