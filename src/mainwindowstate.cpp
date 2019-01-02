#include "mainwindowstate.h"

namespace Luna {

    MainWindowState::MainWindowState( AppDataRef _data )
        :m_data( _data )
    {
        this->m_window = new MainWindow();
        this->m_window->labelUser()->setText(QString::fromStdString(this->m_data->eventHandler->user()->username()));
		this->m_window->labelLevel()->setText(QString::fromStdString(this->m_data->eventHandler->user()->level()));

        QObject::connect(this->m_window->aboutAction(), SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));
		QObject::connect(this->m_window->customerManagerAction(), &QAction::triggered, [=]() { this->createCustomerManagerDialog(); });
		QObject::connect(this->m_customerManagerDialog->saveButton(), &QPushButton::clicked, [=]() { this->CreateUserEvent(); });
    }

    MainWindowState::~MainWindowState()
    {
		delete m_window;
		delete m_customerManagerDialog;
        LUNA_WARN("Main Window State deleted");
    }

    void MainWindowState::Init()
    {
        this->m_window->show();
        LUNA_INFO("Initialized Main Window State");
    }

	void MainWindowState::createCustomerManagerDialog()
	{
		this->m_customerManagerDialog = new ClientManagerDialog();
		LUNA_INFO("Created Customer Manager Dialog");
		this->m_customerManagerDialog->show();
	}
	void MainWindowState::CreateUserEvent()
	{
		if (!this->m_data->eventHandler->LoginHandle(this->m_dialog->userEdit()->text(), this->m_dialog->passEdit()->text()))
		{
			QMessageBox::information(this->m_dialog, "Error!", "Username/Password is incorrect!");
		}
		else {
			this->m_data->machine->AddState(StateRef(new MainWindowState(m_data)), true);
			this->m_data->machine->Update();
		}
	}
}
