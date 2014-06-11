#pragma once

#include <Core/Context.h>
#include "GLEW/glew.h"
#include "GLEW/wglew.h"
#include "GLFW/glfw3.h"

namespace gcore
{
	class GLContext : public Context
	{
	public:
		static GLContext* Create();

		virtual ~GLContext();

		virtual void SetWindow(void* windowID) override;

		virtual void* GetWindow() const override;

		virtual bool Init() override;

		virtual bool MakeCurrent() override;

		virtual bool UnMakeCurrent() override;

		virtual bool SwapBuffers() override;

		virtual bool SetSwapInterval(int interval) override;

		virtual int Width() const override;

		virtual int Height() const override;

		virtual bool IsWindowRunning() override;
		
		virtual void Terminate() override;

		virtual bool PollEvents() override;

	protected:
		GLContext();
		GLFWwindow* mWindow;
	};

	class GLWin32Context : public GLContext
	{
	public:
		GLWin32Context();

		virtual void* GetCurrentContext() override;

		virtual void* GetCurrentDisplay() override;
	};
}