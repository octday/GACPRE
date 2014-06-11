#pragma once

#include <Core/Shader.h>
#include "GLEW/glew.h"

namespace gcore
{
	class GLShader : public Shader
	{
	public:
		GLShader(Type type);
		virtual ~GLShader();

		GLuint GetShader() const;

	public:
		bool Compile();

	private:
		virtual bool Generate() override;
		virtual bool Load() override;
		virtual void UnLoad() override;

		GLuint mShader;
	};

}