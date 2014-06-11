#include <Core/Texture.h>

namespace gcore
{


	Texture::Texture() 
		:mWidth(0)
		, mHeight(0)
	{

	}

	int Texture::Width() const
	{
		return mWidth;
	}

	int Texture::Height() const
	{
		return mHeight;
	}

}