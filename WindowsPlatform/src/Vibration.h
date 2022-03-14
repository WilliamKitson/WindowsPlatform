#pragma once

namespace WindowsPlatform
{
	struct Vibration
	{
	public:
		bool operator==(Vibration);


	public:
		float left{ 0.0f };
		float right{ 0.0f };


	private:
		bool unequalLeft(Vibration);
	};
}

