#pragma once

#include <Core\Resource.h>

namespace gcore
{
	class Shader : public Resource
	{
	public:
		enum Type
		{
			VERTEX,
			TESS_CONTROL,
			TESS_EVALUATION,
			GEOMETRY,
			FRAGMENT,
			COMPUTE
		};

		void LoadShaderFromFile(const std::string& filePath);

		void LoadShaderFromStr(const std::string& shaderStr);

		Type GetType() const;

		const std::string& GetShaderStr() const;

		static Shader* Generate(Type type);

		virtual ~Shader();

	protected:
		Shader(Type type);
	
		std::string mShaderStr;
		Type mType;
	};

	typedef std::shared_ptr<Shader> ShaderPtr;
}