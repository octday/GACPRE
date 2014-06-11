#pragma once

#include <Core\Core.h>

namespace gcore
{
	class CORE_API Resource
	{
	protected:
		Resource() {}
		virtual ~Resource() {}

	public:
		virtual bool Generate() = 0;
		virtual bool Load() = 0;
		virtual void UnLoad() = 0;
	};

}