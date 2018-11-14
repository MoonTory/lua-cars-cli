#include "loginstate.hpp"
#include <iostream>

namespace Luna {

    LoginState::LoginState(AppDataRef _data)
      :m_data( _data )
    {

    }

    void LoginState::Init()
    {
        LUNA_WARN("Initialized Login State");
    }

    void LoginState::Update()
    {
        LUNA_INFO("Updated Login State");
    }

    void LoginState::Render()
    {
        LUNA_INFO("Rendered Login State");
    }

    void LoginState::HandleInput()
    {
        std::cin.get();
    }

}
