//
// Created by minky on 2024-01-20.
//

#ifndef CUI_LOG_H
#define CUI_LOG_H

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#define CM_DEBUG

namespace Cui
{
class Log
{
private:
  Log() = delete;
  Log( const Log& ref ) = delete;
  Log& operator=( const Log& ref ) = delete;
  ~Log() = delete;

private:
  inline static std::shared_ptr<spdlog::logger> s_Logger;

public:
  static std::shared_ptr<spdlog::logger>& GetLogger()
  {
    if ( Log::s_Logger == nullptr )
    {
      spdlog::set_pattern( "%^[%T] %n: %v%$" );
      Log::s_Logger = spdlog::stdout_color_mt( "Cui" );
      Log::s_Logger->set_level( spdlog::level::trace );
    }
    return s_Logger;
  }
};
}// namespace Cui

#if defined( CM_DEBUG )
#  define LOG_TRACE( ... ) ::Cui::Log::GetLogger()->trace( __VA_ARGS__ )
#  define LOG_INFO( ... ) ::Cui::Log::GetLogger()->info( __VA_ARGS__ )
#  define LOG_WARN( ... ) ::Cui::Log::GetLogger()->warn( __VA_ARGS__ )
#  define LOG_ERROR( ... ) ::Cui::Log::GetLogger()->error( __VA_ARGS__ )
#  define LOG_CRITICAL( ... ) ::Cui::Log::GetLogger()->critical( __VA_ARGS__ )
#else                 // Release mode
#  define LOG_TRACE   // do nothing
#  define LOG_INFO    // do nothing
#  define LOG_WARN    // do nothing
#  define LOG_ERROR   // do nothing
#  define LOG_CRITICAL// do nothing
#endif                // DEBUG_MODE

#endif//CUI_LOG_H
