#pragma once

namespace WindowsPlatform
{
	class ResolutionValidator
	{
	public:
		ResolutionValidator();
		~ResolutionValidator();

		int getWidth();
		int getHeight();
		void setResolution(int, int);


	private:
		int validateMinimum(int, int);


	private:
		int resolution[2];
	};
}

