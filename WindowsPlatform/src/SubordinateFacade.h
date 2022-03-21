#pragma once

namespace WindowsPlatform
{
	class SubordianteFacade
	{
	public:
		SubordianteFacade();
		virtual ~SubordianteFacade();

		virtual bool getQuit();
		virtual bool getMinimise();
	};
}

