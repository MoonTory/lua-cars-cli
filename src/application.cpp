#include "application.hpp"
#include "loginstate.hpp"
#include <iostream>

namespace Luna {

    Application::Application(int argc, char *argv[])
        :QApplication(argc, argv)
    {
      Log::Init();

      std::cout << R"()" << "\n\n\n";

      this->m_data->machine.AddState(StateRef( new LoginState( this->m_data ) ));

      this->m_isRunning = true;

      this->Run();
    }

    Application::~Application() { }

    void Application::Run()
    {
        this->m_data->machine.Update();
    }

}
