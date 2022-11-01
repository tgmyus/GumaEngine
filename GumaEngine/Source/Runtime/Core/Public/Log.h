#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Guma
{
	class GUMA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> EngineLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;
	};
}

#define GUMA_ENGINE_TRACE(...) ::Guma::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define GUMA_ENGINE_DEBUG(...) ::Guma::Log::GetEngineLogger()->debug(__VA_ARGS__)
#define GUMA_ENGINE_INFO(...)  ::Guma::Log::GetEngineLogger()->info(__VA_ARGS__)
#define GUMA_ENGINE_WARN(...)  ::Guma::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define GUMA_ENGINE_ERROR(...) ::Guma::Log::GetEngineLogger()->error(__VA_ARGS__)
#define GUMA_ENGINE_CRITICAL(...) ::Guma::Log::GetEngineLogger()->critical(__VA_ARGS__)

#define GUMA_APP_TRACE(...) ::Guma::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GUMA_APP_DEBUG(...) ::Guma::Log::GetClientLogger()->debug(__VA_ARGS__)
#define GUMA_APP_INFO(...)  ::Guma::Log::GetClientLogger()->info(__VA_ARGS__)
#define GUMA_APP_WARN(...)  ::Guma::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GUMA_APP_ERROR(...) ::Guma::Log::GetClientLogger()->error(__VA_ARGS__)
#define GUMA_APP_CRITICAL(...) ::Guma::Log::GetClientLogger()->critical(__VA_ARGS__)
