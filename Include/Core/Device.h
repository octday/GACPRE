#pragma once

#include <Core/Core.h>
#include <Base/Matrix.h>
#include <Core/CoreDefinition.h>

namespace gcore
{
	class Device
	{
	public:
		Device();

		static Device* Instance();

		virtual ~Device();

		virtual void SetDrawBuffers(const BufferTypeList& buffers) = 0;

		virtual void SetReadBuffer(BufferType buffer) = 0;

		virtual void SetViewport(int x, int y, int width, int height) = 0;

		virtual void CleanBuffers(const gbase::Vector4& color, double depth = 0.0, int stencil = 0) = 0;

		virtual void DrawPrimtives() = 0;

		virtual void SetIsEnableDepthTest(bool isEnable) = 0;

		virtual void SetModelMatirx(const gbase::Matrix4& modelMatirx) = 0;

		virtual void SetViewMatirx(const gbase::Matrix4& viewMatirx) = 0;

		virtual void SetModelViewMatirx(const gbase::Matrix4& modelViewMatirx) = 0;

		virtual void SetProjectionMatirx(const gbase::Matrix4& projMatrix) = 0;

		virtual void SetModelViewProjectionMatirx(const gbase::Matrix4& modelViewProjMatrix) = 0;

	protected:
		BufferTypeList mCacheDrawBuffers;
	};

}