#include "GLShaderProgram.h"
#include "GLShader.h"

namespace gcore
{

	GLShaderProgram::GLShaderProgram()
		:mProgram(0U)
	{
		Generate();
	}

	GLShaderProgram::~GLShaderProgram()
	{
		UnLoad();
	}

	void GLShaderProgram::SetIsActive(bool isActive)
	{
		if (isActive)
		{
			glUseProgram(mProgram);
		}
		else
		{
			glUseProgram(0);
		}
	}

	bool GLShaderProgram::SetUniformBool(Location* location, bool b)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform1i(locationID, (GLint)b);
		return true;
	}

	bool GLShaderProgram::SetUniformInt(Location* location, int i)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform1i(locationID, (GLint)i);
		return true;
	}

	bool GLShaderProgram::SetUniformFloat(Location* location, float f)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform1f(locationID, (GLfloat)f);
		return true;
	}

	bool GLShaderProgram::SetUniformDouble(Location* location, double d)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform1d(locationID, (GLdouble)d);
		return true;
	}

	bool GLShaderProgram::SetUniformIntVector2(Location* location, const gbase::IVector2& ivec2)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform2iv(locationID, 1, (const GLint*)ivec2);
		return true;
	}

	bool GLShaderProgram::SetUniformFloatVector2(Location* location, const gbase::Vector2& vec2)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform2fv(locationID, 1, (const GLfloat*)vec2);
		return true;
	}

	bool GLShaderProgram::SetUniformDoubleVector2(Location* location, const gbase::DVector2&dvec2)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform2dv(locationID, 1, (const GLdouble*)dvec2);
		return true;
	}

	bool GLShaderProgram::SetUniformIntVector3(Location* location, const gbase::IVector3& ivec3)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform3iv(locationID, 1, (const GLint*)ivec3);
		return true;
	}

	bool GLShaderProgram::SetUniformFloatVector3(Location* location, const gbase::Vector3& vec3)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform3fv(locationID, 1, (const GLfloat*)vec3);
		return true;
	}

	bool GLShaderProgram::SetUniformDoubleVector3(Location* location, const gbase::DVector3& dvec3)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform3dv(locationID, 1, (const GLdouble*)dvec3);
		return true;
	}

	bool GLShaderProgram::SetUniformIntVector4(Location* location, const gbase::IVector4& ivec4)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform4iv(locationID, 1, (const GLint*)ivec4);
		return true;
	}

	bool GLShaderProgram::SetUniformFloatVector4(Location* location, const gbase::Vector4& vec4)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform4fv(locationID, 1, (const GLfloat*)vec4);
		return true;
	}

	bool GLShaderProgram::SetUniformDoubleVector4(Location* location, const gbase::DVector4& dvec4)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniform4dv(locationID, 1, (const GLdouble*)dvec4);
		return true;
	}

	bool GLShaderProgram::SetUniformFloatMatrix3(Location* location, const gbase::Matrix3& mat3)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniformMatrix3fv(locationID, 1, GL_FALSE, (const GLfloat*)mat3);
		return true;
	}

	bool GLShaderProgram::SetUniformDoubleMatrix3(Location* location, const gbase::DMatrix3& dmat3)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniformMatrix3dv(locationID, 1, GL_FALSE, (const GLdouble*)dmat3);
		return true;
	}

	bool GLShaderProgram::SetUniformFloatMatrix4(Location* location, const gbase::Matrix4& mat4)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniformMatrix4fv(locationID, 1, GL_FALSE, (const GLfloat*)mat4);
		return true;
	}

	bool GLShaderProgram::SetUniformDoubleMatrix4(Location* location, const gbase::DMatrix4& dmat4)
	{
		GLint locationID = static_cast<GLLocation*>(location)->GetLocation();
		if (locationID == -1)
			return false;

		glUniformMatrix4dv(locationID, 1, GL_FALSE, (const GLdouble*)dmat4);
		return true;
	}

	ShaderProgram::Location* GLShaderProgram::GetAttributeLocation(const std::string& name)
	{
		GLint attributeLocation = glGetAttribLocation(mProgram, name.c_str());
		GLLocation* location = new GLLocation();
		location->SetLocation(attributeLocation);
		return location;
	}

	ShaderProgram::Location* GLShaderProgram::GetUniformLocation(const std::string& name)
	{
		GLint uniformLocation = glGetUniformLocation(mProgram, name.c_str());
		GLLocation* location = new GLLocation();
		location->SetLocation(uniformLocation);
		return location;
	}

	bool GLShaderProgram::Generate()
	{
		mProgram = glCreateProgram();
		return mProgram > 0 ? true : false;
	}

	bool GLShaderProgram::Load()
	{
		if (mProgram == 0) 
			return false;

		bool loaded = false;
		if (mVertexShader != nullptr)
		{
			GLuint vs = static_cast<GLShader*>(mVertexShader.get())->GetShader();
			if (vs > 0)
			{
				glAttachShader(mProgram, vs);
				loaded = true;
			}	
		}
		
		if (mTessControlShader != nullptr)
		{
			GLuint tcs = static_cast<GLShader*>(mTessControlShader.get())->GetShader();
			if (tcs > 0)
			{
				glAttachShader(mProgram, tcs);
				loaded = true;
			}
		}
		
		if (mTessEvaluationShader != nullptr)
		{
			GLuint tes = static_cast<GLShader*>(mTessEvaluationShader.get())->GetShader();
			if (tes > 0)
			{
				glAttachShader(mProgram, tes);
				loaded = true;
			}
		}
		
		if (mGeometryShader != nullptr)
		{
			GLuint gs = static_cast<GLShader*>(mGeometryShader.get())->GetShader();
			if (gs > 0)
			{
				glAttachShader(mProgram, gs);
				loaded = true;
			}
		}

		if (mFragmentShader != nullptr)
		{
			GLuint fs = static_cast<GLShader*>(mFragmentShader.get())->GetShader();
			if (fs > 0)
			{
				glAttachShader(mProgram, fs);
				loaded = true;
			}
		}
	
		if (mComputeShader != nullptr)
		{
			GLuint cs = static_cast<GLShader*>(mComputeShader.get())->GetShader();
			if (cs > 0)
			{
				glAttachShader(mProgram, cs);
				loaded = true;
			}
		}

		return loaded;
	}

	void GLShaderProgram::UnLoad()
	{
		if (mProgram == 0)
			return;

		if (mVertexShader != nullptr)
		{
			GLuint vs = static_cast<GLShader*>(mVertexShader.get())->GetShader();
			if (vs > 0)
			{
				glDetachShader(mProgram, vs);
			}
		}

		if (mTessControlShader != nullptr)
		{
			GLuint tcs = static_cast<GLShader*>(mTessControlShader.get())->GetShader();
			if (tcs > 0)
			{
				glDetachShader(mProgram, tcs);
			}
		}

		if (mTessEvaluationShader != nullptr)
		{
			GLuint tes = static_cast<GLShader*>(mTessEvaluationShader.get())->GetShader();
			if (tes > 0)
			{
				glDetachShader(mProgram, tes);
			}
		}

		if (mGeometryShader != nullptr)
		{
			GLuint gs = static_cast<GLShader*>(mGeometryShader.get())->GetShader();
			if (gs > 0)
			{
				glDetachShader(mProgram, gs);
			}
		}

		if (mFragmentShader != nullptr)
		{
			GLuint fs = static_cast<GLShader*>(mFragmentShader.get())->GetShader();
			if (fs > 0)
			{
				glDetachShader(mProgram, fs);
			}
		}

		if (mComputeShader != nullptr)
		{
			GLuint cs = static_cast<GLShader*>(mComputeShader.get())->GetShader();
			if (cs > 0)
			{
				glDetachShader(mProgram, cs);
			}
		}

		glUseProgram(0);
		glDeleteProgram(mProgram);
	}

	bool GLShaderProgram::Link()
	{
		if (mProgram == 0)
			return false;

		glLinkProgram(mProgram);

		GLint success;
		glGetProgramiv(mProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			GLint infoLogLength;
			glGetProgramiv(mProgram, GL_INFO_LOG_LENGTH, &infoLogLength);

			GLchar* infoLog = new GLchar[infoLogLength + 1];
			glGetProgramInfoLog(mProgram, infoLogLength, nullptr, infoLog);
			delete[] infoLog;

			return false;
		}
		else
		{
			return true;
		}
	}

	GLuint GLShaderProgram::GetProgram() const
	{
		return mProgram;
	}

}