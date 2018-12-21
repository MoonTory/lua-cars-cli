#include "application.hpp"
#include "loginstate.hpp"

namespace Luna {

    Application::Application(int argc, char *argv[])
        :QApplication(argc, argv)
    {
		// Initializing Application Data.
		Log::Init();
		this->m_data->machine = new StateMachine();
		this->m_data->eventHandler = new EventHandler();
		this->m_data->machine->AddState(StateRef( new LoginState( this->m_data ) ));
		this->m_data->m_isRunning = true;
		this->Run();
    }

    Application::~Application() { }

    void Application::Run()
    {
		// Kickstart the State Machine.
        this->m_data->machine->Update();
    }

}
