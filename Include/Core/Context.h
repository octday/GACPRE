#pragma once

#include <Core\Core.h>

namespace gcore
{
	class CORE_API Context
	{
	public:
		virtual bool Init() = 0;

		virtual void SetWindow(void* windowID) = 0;

		virtual void* GetWindow() const = 0;

		virtual bool MakeCurrent() = 0;

		virtual bool UnMakeCurrent() = 0;

		virtual bool SwapBuffers() = 0;

		virtual bool SetSwapInterval(int interval) = 0;

		virtual void* GetCurrentContext() = 0;

		virtual void* GetCurrentDisplay() = 0;

		virtual int Width() const = 0;

		virtual int Height() const = 0;

		virtual void Terminate() = 0;

		virtual bool IsWindowRunning() = 0;

		virtual bool PollEvents() = 0;
	};
}