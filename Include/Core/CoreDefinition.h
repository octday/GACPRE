#pragma once

#include <Core/Core.h>

namespace gcore
{
	enum BufferType
	{
		NONE_BUFFER,
		BACK_LEFT_COLOR_BUFFER,
		COLOR_ATTACHMENT0_BUFFER,
		COLOR_ATTACHMENT1_BUFFER,
		COLOR_ATTACHMENT2_BUFFER,
		COLOR_ATTACHMENT3_BUFFER,
		COLOR_ATTACHMENT4_BUFFER,
		COLOR_ATTACHMENT5_BUFFER,
		COLOR_ATTACHMENT6_BUFFER,
		COLOR_ATTACHMENT7_BUFFER,
		DEPTH_BUFFER,
		STENCIL_BUFFER,
	};

	typedef std::vector<BufferType> BufferTypeList;
	static BufferTypeList NoneBuffer = { NONE_BUFFER };
	static BufferTypeList BackLeftColorBuffer = { BACK_LEFT_COLOR_BUFFER };
	static BufferTypeList BackLeftColorDepthAndStencilBuffers = { BACK_LEFT_COLOR_BUFFER, DEPTH_BUFFER, STENCIL_BUFFER };
	static BufferTypeList BackLeftAndAttachment0ColorBuffers = { BACK_LEFT_COLOR_BUFFER, COLOR_ATTACHMENT0_BUFFER };
}