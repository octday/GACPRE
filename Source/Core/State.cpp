#include <Core/State.h>

namespace gcore
{

	State::State()
		:mEnableDepthTest(true)
	{

	}

	State::~State()
	{

	}

	void State::SetIsEnableDepthTest(bool isEnable)
	{
		mEnableDepthTest = isEnable;
	}

	bool State::GetIsEnableDepthTest() const
	{
		return mEnableDepthTest;
	}

	void State::CleanTexture()
	{
		mTextures.clear();
	}

	void State::AddTexture(Texture* texture)
	{
		mTextures.push_back(TexturePtr(texture));
	}

	void State::RemoveTexture(unsigned int pass)
	{
		if (pass < mTextures.size())
		{
			auto iter = std::find(mTextures.begin(), mTextures.end(), mTextures.at(pass));
			mTextures.erase(iter);
		}
	}

	void State::RemoveTexture(Texture* texture)
	{
		auto iter = std::find(mTextures.begin(), mTextures.end(), TexturePtr(texture));
		if (iter != mTextures.end())
		{
			mTextures.erase(iter);
		}
	}

	Texture* State::GetTexture(unsigned int pass) const
	{
		if (pass < mTextures.size())
		{
			return mTextures.at(pass).get();
		}
		else
		{
			return nullptr;
		}
	}

	unsigned int State::GetTextureCount() const
	{
		return mTextures.size();
	}

	void State::SetShaderProgram(ShaderProgram* program)
	{
		mProgram = ShaderProgramPtr(program);
	}

	ShaderProgram* State::GetShaderProgram() const
	{
		return mProgram.get();
	}

}