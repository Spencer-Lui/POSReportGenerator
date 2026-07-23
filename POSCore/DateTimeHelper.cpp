#include "DateTimeHelper.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string DateTimeHelper::GetCurrentTimestamp()
{
    auto now =
        std::chrono::system_clock::now();

    auto time =
        std::chrono::system_clock::to_time_t(now);

    std::tm localTime{};

#ifdef _WIN32
    localtime_s(&localTime, &time);
#else
    localtime_r(&time, &localTime);
#endif

    std::ostringstream oss;

    oss << std::put_time(
        &localTime,
        "%Y%m%d_%H%M%S");

    return oss.str();
}
