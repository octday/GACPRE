#pragma once

#include <Core/Core.h>
#include <Base/Vector.h>

namespace gcore
{
	class Texture;
	class Device;
	class Context;

	class RenderTarget
	{
	public:
		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;

		void SetBackgroundColor(const gbase::Vector4& color);
		const gbase::Vector4& GetBackgroundColor() const;

		virtual void BeginDraw(Device* device) = 0;
		virtual void EndDraw(Device* device) = 0;

		virtual void BeginRead(Device* device) = 0;
		virtual void EndRead(Device* device) = 0;

		virtual ~RenderTarget() {}

	protected:
		RenderTarget() {}
		gbase::Vector4 mBackgroundColor;
	};

	typedef std::shared_ptr<RenderTarget> RenderTargetPtr;

	class BackBufferTarget : public RenderTarget
	{
	public:
		virtual int GetWidth() override;
		virtual int GetHeight() override;

		virtual void BeginDraw(Device* device) override;
		virtual void EndDraw(Device* device) override;

		virtual void BeginRead(Device* device) override;
		virtual void EndRead(Device* device) override;

		BackBufferTarget(Context* context);

		virtual ~BackBufferTarget();

	protected:
		Context* mContext;
	};

	class TextureTarget : public RenderTarget
	{
	public:
		TextureTarget(Texture* texture);

		virtual int GetWidth() override;
		virtual int GetHeight() override;

		virtual void BeginDraw(Device* device) override;
		virtual void EndDraw(Device* device) override;

		virtual void BeginRead(Device* device) override;
		virtual void EndRead(Device* device) override;

	protected:
		Texture* mTexture;
	};

	class FramwBufferTarget : public RenderTarget
	{
	public:
		FramwBufferTarget(int width, int height);

		virtual int GetWidth() override;
		virtual int GetHeight() override;

		virtual void BeginDraw(Device* device) override;
		virtual void EndDraw(Device* device) override;

		virtual void BeginRead(Device* device) override;
		virtual void EndRead(Device* device) override;

		void SetRange(int width, int height);

	protected:
		int mWidth;
		int mHight;
	};
}
