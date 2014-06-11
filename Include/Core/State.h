#pragma once

#include <Core\Texture.h>
#include <Core\ShaderProgram.h>

namespace gcore
{
	class CORE_API State
	{
	public:
		State();

		virtual ~State();

		void SetIsEnableDepthTest(bool isEnable);

		bool GetIsEnableDepthTest() const;

		void AddTexture(Texture* texture);

		void RemoveTexture(unsigned int pass);

		void RemoveTexture(Texture* texture);

		unsigned int GetTextureCount() const;

		Texture* GetTexture(unsigned int pass) const;

		void CleanTexture();

		void SetShaderProgram(ShaderProgram* program);

		ShaderProgram* GetShaderProgram() const;

	protected:
		TexturePtrList mTextures;
		ShaderProgramPtr mProgram;
		bool mEnableDepthTest;
	};
}