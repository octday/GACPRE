#pragma once

#include <Core/CoreDefinition.h>
#include <Core/Shader.h>
#include "GLEW/glew.h"

namespace gcore
{
	class GLTypeConverter
	{
	public:
		static GLenum GetGLBufferType(BufferType bufferType);

		static GLenum GetGLShaderType(Shader::Type shaderType);
	};
}