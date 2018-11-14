#include "application.hpp"
#include "loginstate.hpp"
#include <iostream>
#include <cstdlib>


namespace Luna {

    Application::Application()
    {
      Log::Init();

      std::cout << R"(   _   _   _ _  _   _      ___   _   ___  ___
  | | | | | | \| | /_\    / __| /_\ | _ \/ __|
  | |_| |_| | .` |/ _ \  | (__ / _ \|   /\__ \
  |____\___/|_|\_/_/ \_\  \___/_/ \_\_|_\|___/
  --------------------------------------------
|-- Developed by: Gustavo Quinta (MoonTory)  --|
|-- https://github.com/MoonTory/lua-cars-cli --|)" << "\n\n\n";

      this->m_data->machine.AddState(StateRef( new LoginState( this->m_data ) ));

      this->m_isRunning = true;

      this->Run();
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
      while (this->m_isRunning)
      {

          this->m_data->machine.Update();
          this->m_data->machine.GetActiveState()->Update();
          this->m_data->machine.GetActiveState()->HandleInput();
          this->m_data->machine.GetActiveState()->Render();
      }
    }

}
