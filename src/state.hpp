#ifndef STATE_HPP
#define STATE_HPP

namespace Luna {

    class State
    {
    public:
        ~State() = default;

        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void HandleInput() = 0;
        virtual void Render() = 0;

        virtual void Pause() { }
        virtual void Resume() { }
    };

}

#endif // STATE_HPP
