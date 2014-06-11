#include "GLShader.h"
#include "GLTypeConverter.h"

namespace gcore
{

	GLShader::GLShader(Type type)
		:Shader(type)
		, mShader(0)
	{
		Generate();
	}

	GLShader::~GLShader()
	{
		UnLoad();
	}

	bool GLShader::Generate()
	{
		GLenum shaderType = GLTypeConverter::GetGLShaderType(mType);
		mShader = glCreateShader(shaderType);
		return mShader > 0 ? true : false;
	}

	bool GLShader::Load()
	{
		const std::string& shaderSrc = GetShaderStr();
		const GLchar* shaderStringPtr[1];
		shaderStringPtr[0] = shaderSrc.c_str();
		int shaderStrLength[1];
		shaderStrLength[0] = shaderSrc.length();
		glShaderSource(mShader, 1, (const GLchar **)shaderStringPtr, shaderStrLength);
		return true;
	}

	bool GLShader::Compile()
	{
		glCompileShader(mShader);

		GLint success;
		glGetShaderiv(mShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			GLint infoLogLength;
			glGetProgramiv(mShader, GL_INFO_LOG_LENGTH, &infoLogLength);

			GLchar* infoLog = new GLchar[infoLogLength + 1];

			glGetShaderInfoLog(mShader, infoLogLength, nullptr, infoLog);
			return false;
		}
		else
		{
			return true;
		}
	}

	void GLShader::UnLoad()
	{
		if (mShader > 0)
		{
			glDeleteShader(mShader);
			mShader = 0;
		}
	}

	GLuint GLShader::GetShader() const
	{
		return mShader;
	}

}