#pragma once

#include <Core/Device.h>


namespace gcore
{
	class GLDevice : public Device
	{
	public:
		GLDevice();

		virtual ~GLDevice();

		virtual void SetDrawBuffers(const BufferTypeList& buffers) override;

		virtual void SetReadBuffer(BufferType buffer) override;

		virtual void SetViewport(int x, int y, int width, int height) override;

		virtual void CleanBuffers(const gbase::Vector4& color, double depth, int stencil) override;

		virtual void DrawPrimtives() override;

		virtual void SetIsEnableDepthTest(bool isEnable) override;

		virtual void SetModelMatirx(const gbase::Matrix4& modelMatirx) override;

		virtual void SetViewMatirx(const gbase::Matrix4& viewMatirx) override;

		virtual void SetModelViewMatirx(const gbase::Matrix4& modelViewMatirx) override;

		virtual void SetProjectionMatirx(const gbase::Matrix4& projMatrix) override;

		virtual void SetModelViewProjectionMatirx(const gbase::Matrix4& modelViewProjMatrix) override;

	private:

	};
}