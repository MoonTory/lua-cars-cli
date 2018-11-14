#ifndef LOGINSTATE_HPP
#define LOGINSTATE_HPP

#include "state.hpp"
#include "application.hpp"

namespace Luna {

    class LoginState : public State
    {
    public:
        LoginState( AppDataRef _data );

        void Init()         override;
        void Update()       override;
        void Render()       override;
        void HandleInput()  override;
    private:
        AppDataRef m_data;
    };

}

#endif // LOGINSTATE_HPP
