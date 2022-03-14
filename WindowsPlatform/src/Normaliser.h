#pragma once

namespace WindowsPlatform
{
	class Normaliser
	{
	public:
		Normaliser();
		Normaliser(float, float);
		~Normaliser();

		void normalise(float, float, float);
		float getNormalised();


	private:
		float getSmaller(float, float);
		float getLarger(float, float);


	private:
		const float minimum;
		const float maximum;
		float normalised;
	};
}

