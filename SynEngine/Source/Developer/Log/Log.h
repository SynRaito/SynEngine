#pragma once

#include <memory>

#include "../../Runtime/Core/Core.h"
#include "spdlog/spdlog.h"


namespace Syn{

	class SYN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return engineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetGameLogger() { return gameLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> gameLogger;
		static std::shared_ptr<spdlog::logger> engineLogger;

	};

}

//Engine Log Macros
#define SYN_ENGINE_ERROR(...) ::Syn::Log::GetEngineLogger()->error(__VA_ARGS__)
#define SYN_ENGINE_WARN(...)  ::Syn::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define SYN_ENGINE_INFO(...)  ::Syn::Log::GetEngineLogger()->info(__VA_ARGS__)
#define SYN_ENGINE_TRACE(...) ::Syn::Log::GetEngineLogger()->trace(__VA_ARGS__)
//Game Log Macros
#define SYN_GAME_ERROR(...)   ::Syn::Log::GetGameLogger()->error(__VA_ARGS__)
#define SYN_GAME_WARN(...)    ::Syn::Log::GetGameLogger()->warn(__VA_ARGS__)
#define SYN_GAME_INFO(...)    ::Syn::Log::GetGameLogger()->info(__VA_ARGS__)
#define SYN_GAME_TRACE(...)   ::Syn::Log::GetGameLogger()->trace(__VA_ARGS__)