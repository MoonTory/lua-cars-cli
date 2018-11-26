#ifndef STATE_HPP
#define STATE_HPP

namespace Luna {

    class State
    {
    public:
        ~State() = default;

        virtual void Init() = 0;

        virtual void Pause() { }
        virtual void Resume() { }
    };

} // namespace luna

#endif // STATE_HPP
