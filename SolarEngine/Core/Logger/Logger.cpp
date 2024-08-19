#include "Logger.h"
#include <spdlog/spdlog.h>
#include <spdlog/common.h>

namespace Solar {
    std::shared_ptr<spdlog::logger> Logger::sCoreLogger = nullptr;
    std::shared_ptr<spdlog::logger> Logger::sClientLogger = nullptr;

    void Logger::Init() {
       spdlog::set_pattern("%^[%H:%M:%S] [%!:%#] [%n] [thread %t] %v%$"); 

       sCoreLogger = spdlog::stdout_color_mt("Solar Engine");
       sCoreLogger->set_level(spdlog::level::trace);

       sClientLogger = spdlog::stdout_color_mt("Client");
       sClientLogger->set_level(spdlog::level::trace);

       CORE_LOG_INFO("Init logger successfuly");
    }
} 