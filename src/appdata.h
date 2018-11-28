#ifndef APPDATA_H
#define APPDATA_H

#include "statemachine.hpp"
#include "eventhandler.h"

namespace Luna {

    struct AppData
    {
        StateMachine *machine;
        EventHandler *eventHandler;
    };

    typedef std::shared_ptr<AppData> AppDataRef;

}

#endif // APPDATA_H
