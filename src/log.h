#ifndef LOG_H
#define LOG_H

#include <memory>
#include <spdlog/spdlog.h>

namespace Luna {

    class Log // Global Log class for application wide logging
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return m_CoreLogger; }
    private:
        static std::shared_ptr<spdlog::logger> m_CoreLogger;
    };

} // namespace luna

// Defining LOG MACROS
#define LUNA_TRACE(...)    ::Luna::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LUNA_INFO(...)     ::Luna::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LUNA_WARN(...)     ::Luna::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LUNA_ERROR(...)    ::Luna::Log::GetCoreLogger()->error(__VA_ARGS__)

#endif // LOG_H
