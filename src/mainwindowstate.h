#ifndef MAINWINDOWSTATE_H
#define MAINWINDOWSTATE_H

#include "state.hpp"
#include <string>
#include "application.hpp"
#include "Forms/MainWindow/mainwindow.h"
#include "Forms/ClientManagerDialog/clientmanagerdialog.h"

namespace Luna {

    class MainWindowState : public State
    {
    public:
        MainWindowState( AppDataRef _data );
        ~MainWindowState() override;

        // State method override
        void Init() override;
		void createCustomerManagerDialog();

		void CreateUserEvent();

    private:
        AppDataRef m_data;
		MainWindow *m_window;
		ClientManagerDialog *m_customerManagerDialog;
    };

} // namespace Luna

#endif // MAINWINDOWSTATE_H
