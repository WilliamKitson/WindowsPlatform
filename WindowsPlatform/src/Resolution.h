#pragma once

namespace WindowsPlatform
{
	struct Resolution
	{
	public:
		bool operator==(Resolution);


	public:
		int width{ 0 };
		int height{ 0 };
	};
}

