#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stack>
#include "src/state.hpp"

namespace Luna {

    typedef std::unique_ptr<State> StateRef;

    class StateMachine
    {
    public:
        StateMachine() { }
        ~StateMachine() { }

        void AddState( StateRef _newState, bool _isReplacing = true );
        void RemoveState();
        void Update();

        StateRef &GetActiveState();
    private:
        std::stack<StateRef> m_states;
        StateRef m_newState;

        bool m_isAdding, m_isRemoving, m_isReplacing;
    };

} // namespace luna


#endif // STATEMACHINE_H
