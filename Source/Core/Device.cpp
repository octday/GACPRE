#include <Core/Device.h>
#include <Core/Configuration.h>
#include "GL/GLDevice.h"

namespace gcore
{
	Device::Device()
	{

	}

	Device::~Device()
	{

	}

	Device* Device::Instance()
	{
		if (Configuration::Instance()->GetGraphicsAPI() == Configuration::OPENGL)
		{
			static GLDevice instance;
			return &instance;
		}
		else
		{
			return nullptr;
		}
	}

}



