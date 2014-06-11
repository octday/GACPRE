#include <Core/RenderTarget.h>
#include <Core/Texture.h>
#include <Core/Device.h>
#include <Core/Context.h>

namespace gcore
{
	void RenderTarget::SetBackgroundColor(const gbase::Vector4& color)
	{
		mBackgroundColor = color;
	}

	const gbase::Vector4& RenderTarget::GetBackgroundColor() const
	{
		return mBackgroundColor;
	}

	BackBufferTarget::~BackBufferTarget()
	{

	}

	BackBufferTarget::BackBufferTarget(Context* context)
		:mContext(context)
	{

	}

	int BackBufferTarget::GetWidth()
	{
		return mContext->Width();
	}

	int BackBufferTarget::GetHeight()
	{
		return mContext->Height();
	}

	void BackBufferTarget::BeginDraw(Device* device)
	{
		device->SetDrawBuffers(BackLeftColorBuffer);
		device->SetViewport(0, 0, GetWidth(), GetHeight());
		device->CleanBuffers(mBackgroundColor);
	}

	void BackBufferTarget::EndDraw(Device* device)
	{
		mContext->SwapBuffers();
	}

	void BackBufferTarget::BeginRead(Device* device)
	{
		device->SetReadBuffer(BACK_LEFT_COLOR_BUFFER);
	}

	void BackBufferTarget::EndRead(Device* device)
	{

	}

	int TextureTarget::GetWidth()
	{
		return mTexture->Width();
	}

	int TextureTarget::GetHeight()
	{
		return mTexture->Height();
	}

	TextureTarget::TextureTarget(Texture* texture)
		:mTexture(texture)
	{

	}

	void TextureTarget::BeginDraw(Device* device)
	{

	}

	void TextureTarget::EndDraw(Device* device)
	{

	}

	void TextureTarget::BeginRead(Device* device)
	{

	}

	void TextureTarget::EndRead(Device* device)
	{

	}

	int FramwBufferTarget::GetWidth()
	{
		return 0;
	}

	int FramwBufferTarget::GetHeight()
	{
		return 0;
	}

	FramwBufferTarget::FramwBufferTarget(int width, int height)
		:mWidth(width)
		, mHight(height)
	{

	}

	void FramwBufferTarget::BeginDraw(Device* device)
	{

	}

	void FramwBufferTarget::EndDraw(Device* device)
	{

	}

	void FramwBufferTarget::BeginRead(Device* device)
	{

	}

	void FramwBufferTarget::EndRead(Device* device)
	{

	}

	void FramwBufferTarget::SetRange(int width, int height)
	{
		if (mWidth == width && mHight == height)
			return;

		mWidth = width;
		mHight = height;
	}

}