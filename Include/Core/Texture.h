#pragma once

#include <Core\Resource.h>

namespace gcore
{
	class CORE_API Texture : public Resource
	{
	public:
		Texture();

		virtual ~Texture() {}

		virtual bool InitByImage(const std::wstring& file) = 0;

		virtual bool Reserve(int width, int height) = 0;

		int Width() const;

		int Height() const;

		virtual bool Generate() override { return false; }
		virtual bool Load() override { return false; }
		virtual void UnLoad() override {  }

	protected:
		int mWidth;
		int mHeight;
	};

	typedef std::shared_ptr<Texture> TexturePtr;
	typedef std::vector<TexturePtr> TexturePtrList;
}