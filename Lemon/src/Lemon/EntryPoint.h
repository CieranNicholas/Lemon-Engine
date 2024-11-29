#pragma once

#ifdef LEM_PLATFORM_WINDOWS

extern Lemon::Application* Lemon::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lemon::CreateApplication();
	app->Run();
	delete app;
}

#endif