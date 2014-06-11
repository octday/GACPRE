#pragma once

#include <Core\Core.h>

namespace gcore
{
	class CORE_API Configuration
	{
	public:
		enum GraphicsAPI
		{
			OPENGL,
			DIRECTX
		};

		static Configuration* Instance();

		void SetGraphicsAPI(GraphicsAPI api);

		GraphicsAPI GetGraphicsAPI() const;

	protected:
		Configuration();
		~Configuration() {}

	protected:
		GraphicsAPI mGraphicsAPI;
	};
}