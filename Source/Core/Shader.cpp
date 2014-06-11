#include <Core/Shader.h>
#include <Core/Configuration.h>
#include "Gl/GLShader.h"

namespace gcore
{

	Shader::Shader(Type type)
		:mType(type)
	{

	}

	void Shader::LoadShaderFromFile(const std::string& filePath)
	{
		std::ifstream sourceFile;

		sourceFile.open(filePath.c_str(), std::ios::binary);
		if (!sourceFile)
		{
			return;
		}

		sourceFile.seekg(0, std::ios::end);
		int length = int(sourceFile.tellg());
		char *text = new char[length + 1];
		sourceFile.seekg(0, std::ios::beg);
		sourceFile.read(text, length);
		sourceFile.close();
		text[length] = '\0';

		LoadShaderFromStr(text);

		delete[] text;
	}

	void Shader::LoadShaderFromStr(const std::string& shaderStr)
	{
		mShaderStr = shaderStr;

		if (Configuration::Instance()->GetGraphicsAPI() == Configuration::OPENGL)
		{
			static_cast<GLShader*>(this)->Compile();
		}
		else
		{
		}
	}

	Shader::Type Shader::GetType() const
	{
		return mType;
	}

	Shader* Shader::Generate(Type type)
	{
		if (Configuration::Instance()->GetGraphicsAPI() == Configuration::OPENGL)
		{
			return new GLShader(type);
		} 
		else
		{
			return nullptr;
		}
	}

	const std::string& Shader::GetShaderStr() const
	{
		return mShaderStr;
	}

	Shader::~Shader()
	{

	}

}