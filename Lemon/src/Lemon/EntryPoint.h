#pragma once

#ifdef LEM_PLATFORM_WINDOWS

extern Lemon::Application* Lemon::CreateApplication();

int main(int argc, char** argv)
{
	Lemon::Log::Init();
	LEM_CORE_WARN("Initialized Log!");
	LEM_INFO("Initialized Client Log!");
	
	auto app = Lemon::CreateApplication();
	app->Run();
	delete app;
}

#endif