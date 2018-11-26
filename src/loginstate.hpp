#ifndef LOGINSTATE_HPP
#define LOGINSTATE_HPP

#include <QDialog>
#include "state.hpp"
#include "application.hpp"

namespace Luna {

    class LoginState : public State
    {
    public:
        LoginState( AppDataRef _data );

        void Init()         override;
    private:
        AppDataRef m_data;
        QDialog m_dialog;
    };

} // namespace luna

#endif // LOGINSTATE_HPP
