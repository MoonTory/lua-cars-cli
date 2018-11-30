#ifndef LOGINSTATE_HPP
#define LOGINSTATE_HPP


#include "state.hpp"
#include "application.hpp"
#include "Forms/LoginDialog/logindialog.h"

namespace Luna {

    class LoginState : public State
    {
    public:
        LoginState( AppDataRef _data );
        ~LoginState() override;

        // State method override
        void Init() override;

        // State Events
        void LoginEvent();
    private:
        AppDataRef m_data;
        LoginDialog *m_dialog;
    };

} // namespace luna

#endif // LOGINSTATE_HPP
