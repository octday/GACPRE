#include <Core/ShaderProgram.h>
#include <Core/Configuration.h>
#include "GL/GLShaderProgram.h"

namespace gcore
{
	ShaderProgram* ShaderProgram::Generate()
	{
		if (Configuration::Instance()->GetGraphicsAPI() == Configuration::OPENGL)
		{
			return new GLShaderProgram();
		} 
		else
		{
			return nullptr;
		}
	}

	ShaderProgram::~ShaderProgram()
	{

	}

	ShaderProgram::ShaderProgram()
	{

	}

	void ShaderProgram::SetVertexShader(Shader* shader)
	{
		mVertexShader = ShaderPtr(shader);
	}

	void ShaderProgram::SetGeometryShader(Shader* shader)
	{
		mGeometryShader = ShaderPtr(shader);
	}

	void ShaderProgram::SetFragmentShader(Shader* shader)
	{
		mFragmentShader = ShaderPtr(shader);
	}

	void ShaderProgram::SetTessControlShader(Shader* shader)
	{
		mTessControlShader = ShaderPtr(shader);
	}

	void ShaderProgram::SetTessEvaluationShader(Shader* shader)
	{
		mTessEvaluationShader = ShaderPtr(shader);
	}

	void ShaderProgram::SetComputeShader(Shader* shader)
	{
		mComputeShader = ShaderPtr(shader);
	}

	Shader* ShaderProgram::GetVertexShader() const
	{
		return mVertexShader.get();
	}

	Shader* ShaderProgram::GetGeometryShader() const
	{
		return mGeometryShader.get();
	}

	Shader* ShaderProgram::GetFragmentShader() const
	{
		return mFragmentShader.get();
	}

	Shader* ShaderProgram::GetTessControlShader() const
	{
		return mTessControlShader.get();
	}

	Shader* ShaderProgram::GetTessEvaluationShader() const
	{
		return mTessEvaluationShader.get();
	}

	Shader* ShaderProgram::GetComputeShader() const
	{
		return mComputeShader.get();
	}


	ShaderProgram::Location* ShaderProgram::Location::Create()
	{
		if (Configuration::Instance()->GetGraphicsAPI() == Configuration::OPENGL)
		{
			return new GLShaderProgram::GLLocation();
		}
		else
		{
			return nullptr;
		}
	}

}
