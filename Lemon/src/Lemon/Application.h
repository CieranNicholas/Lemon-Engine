#pragma once

#include "Core.h"

namespace Lemon {
	class LEMON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
