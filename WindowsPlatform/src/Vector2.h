#pragma once

namespace WindowsPlatform
{
	struct Vector2
	{
	public:
		bool operator==(Vector2);


	public:
		float x{ 0.0f };
		float y{ 0.0f };


	private:
		bool equalX(Vector2);
		bool equalY(Vector2);
	};
}

