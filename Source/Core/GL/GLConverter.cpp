#include "GLTypeConverter.h"

namespace gcore
{
	GLenum GLTypeConverter::GetGLBufferType(BufferType buffer)
	{
		static const GLenum glBuffers[] =
		{
			GL_NONE,
			GL_BACK_LEFT,
			GL_COLOR_ATTACHMENT0,
			GL_COLOR_ATTACHMENT1,
			GL_COLOR_ATTACHMENT2,
			GL_COLOR_ATTACHMENT3,
			GL_COLOR_ATTACHMENT4,
			GL_COLOR_ATTACHMENT5,
			GL_COLOR_ATTACHMENT6,
			GL_COLOR_ATTACHMENT7,
			GL_DEPTH_BUFFER,
			GL_STENCIL_BUFFER,
		};

		return glBuffers[buffer];
	}

	GLenum GLTypeConverter::GetGLShaderType(Shader::Type shaderType)
	{
		static const GLenum glShaderTypes[] =
		{
			GL_VERTEX_SHADER,
			GL_TESS_CONTROL_SHADER,
			GL_TESS_EVALUATION_SHADER, 
			GL_GEOMETRY_SHADER,
			GL_FRAGMENT_SHADER,
			GL_COMPUTE_SHADER,
		};

		return glShaderTypes[shaderType];
	}
}