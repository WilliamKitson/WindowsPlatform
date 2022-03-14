#pragma once

#include <chrono>

namespace WindowsPlatform
{
	class DeltaTimer
	{
	public:
		DeltaTimer();
		~DeltaTimer();

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

