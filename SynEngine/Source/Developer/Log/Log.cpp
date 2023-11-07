#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Syn {

	std::shared_ptr<spdlog::logger> Log::gameLogger;
	std::shared_ptr<spdlog::logger> Log::engineLogger;

	void Log::Init() 
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		engineLogger = spdlog::stdout_color_mt("ENGINE");
		engineLogger->set_level(spdlog::level::trace);

		gameLogger = spdlog::stdout_color_mt("GAME");
		gameLogger->set_level(spdlog::level::trace);
	}

}
