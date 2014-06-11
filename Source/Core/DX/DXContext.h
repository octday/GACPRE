#pragma once

#include <Core/Context.h>
#include <d3dcommon.h>
#include <dxgi.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <d3dx11.h>

namespace gcore
{
	class DXContext : public Context
	{
	public:
		DXContext();

		virtual void SetWindow(void* windowID) override;

		virtual void* GetWindow() const override;

		virtual bool Init() override;

		virtual bool MakeCurrent() override;

		virtual bool UnMakeCurrent() override;

		virtual bool SwapBuffers() override;

		virtual bool SetSwapInterval(int interval) override;

		virtual void* GetCurrentContext() override;

		virtual void* GetCurrentDisplay() override;

		virtual int Width() const override;

		virtual int Height() const override;

		virtual bool IsWindowRunning() override;

		virtual void Terminate() override;

		virtual bool PollEvents() override;

	protected:
		HWND mHwnd;
	};

}