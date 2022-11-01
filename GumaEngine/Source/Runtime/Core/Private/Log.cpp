#include "Precompiled.h"
#include "Log.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Guma
{
	std::shared_ptr<spdlog::logger> Log::EngineLogger;
	std::shared_ptr<spdlog::logger> Log::ClientLogger;

	void Log::Init()
	{
		std::vector<spdlog::sink_ptr> LogSinks;
		LogSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		LogSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Guma.log", true));

		if (!LogSinks[0] || !LogSinks[1])
			return;

		LogSinks[0]->set_pattern("%^[%T] %n: %v%$");
		LogSinks[1]->set_pattern("[%T] [%l] %n: %v");

		EngineLogger = std::make_shared<spdlog::logger>("GUMA", LogSinks.begin(), LogSinks.end());
		ClientLogger = std::make_shared<spdlog::logger>("APP", LogSinks.begin(), LogSinks.end());

		if (!EngineLogger || !ClientLogger)
			return;

		spdlog::register_logger(EngineLogger);
		EngineLogger->set_level(spdlog::level::trace);
		EngineLogger->flush_on(spdlog::level::trace);

		spdlog::register_logger(ClientLogger);
		ClientLogger->set_level(spdlog::level::trace);
		ClientLogger->flush_on(spdlog::level::trace);
	}
}
