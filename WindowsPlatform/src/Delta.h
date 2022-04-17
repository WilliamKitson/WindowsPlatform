#pragma once

#include <chrono>

namespace windowsPlatform
{
	class Delta
	{
	public:
		Delta();
		~Delta();

		void update();
		float getDelta();

	private:
		void calculateDelta();
		void resetStart();

	private:
		float delta;
		std::chrono::time_point<std::chrono::high_resolution_clock> start;
	};
}
