#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Spark::Application* createApp();

int main()
{
	Spark::Log::Init();

	std::cout << "Welcome to Spark!" << std::endl;

	/* --- Test ground --- */

	SP_CORE_LOG_INFO("Hello!")
	SP_LOG_INFO("Hello!")

	/* ------------------- */

	auto app = createApp();
	app->tickUpdate();
	delete app;
}

#endif