#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Lemon
{
    class LEMON_API Log
    {
    public:
        static void Init();
    
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

// Core log macros
#define LEM_CORE_TRACE(...) ::Lemon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LEM_CORE_INFO(...)  ::Lemon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LEM_CORE_WARN(...)  ::Lemon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LEM_CORE_ERROR(...) ::Lemon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LEM_CORE_FATAL(...) ::Lemon::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LEM_TRACE(...)      ::Lemon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LEM_INFO(...)       ::Lemon::Log::GetClientLogger()->info(__VA_ARGS__)
#define LEM_WARN(...)       ::Lemon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LEM_ERROR(...)      ::Lemon::Log::GetClientLogger()->error(__VA_ARGS__)
#define LEM_FATAL(...)      ::Lemon::Log::GetClientLogger()->fatal(__VA_ARGS__)
