#include <Core/Configuration.h>

namespace gcore
{

	Configuration* Configuration::Instance()
	{
		static Configuration instance;
		return &instance;
	}

	Configuration::Configuration() 
		: mGraphicsAPI(OPENGL)
	{

	}

	void Configuration::SetGraphicsAPI(GraphicsAPI api)
	{
		mGraphicsAPI = api;
	}

	gcore::Configuration::GraphicsAPI Configuration::GetGraphicsAPI() const
	{
		return mGraphicsAPI;
	}

}