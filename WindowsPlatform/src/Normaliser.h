#pragma once

namespace WindowsPlatform
{
	class Normaliser
	{
	public:
		Normaliser();
		~Normaliser();

		void normalise(float, float, float);
		float getNormalised();
		void setRange(float, float);


	private:
		float getSmaller(float, float);
		float getLarger(float, float);


	private:
		float minimum;
		float maximum;
		float normalised;
	};
}

