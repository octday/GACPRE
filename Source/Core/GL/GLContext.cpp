#include "GLContext.h"
#include <iostream>

namespace gcore
{
	GLContext::GLContext()
		: mWindow(nullptr)
	{
		
	}

	bool GLContext::MakeCurrent()
	{
		glfwMakeContextCurrent(mWindow);
		return true;
	}

	bool GLContext::UnMakeCurrent()
	{
		glfwMakeContextCurrent(nullptr);
		return true;
	}

	bool GLContext::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
		return true;
	}

	bool GLContext::SetSwapInterval(int interval)
	{
		glfwSwapInterval(interval);
		return false;
	}

	bool GLContext::Init()
	{
#ifdef _DEBUG
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_FOCUSED, GL_TRUE);
		glfwWindowHint(GLFW_DECORATED, GL_TRUE);
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_RED_BITS, 8);
		glfwWindowHint(GLFW_GREEN_BITS, 8);
		glfwWindowHint(GLFW_BLUE_BITS, 8);
		glfwWindowHint(GLFW_ALPHA_BITS, 8);
		glfwWindowHint(GLFW_DEPTH_BITS, 24);
		glfwWindowHint(GLFW_STENCIL_BITS, 0);

		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			/* Problem: glewInit failed, something is seriously wrong. */
			std::cout << glewGetErrorString(err) << std::endl;
			//fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
			return false;
		}
		const GLubyte *oglVersion = glGetString(GL_VERSION);
		//fprintf(stdout, "Using GLEW %s\n", glewGetString(GLEW_VERSION));

		return true;
	}

	void GLContext::Terminate()
	{
		if (IsWindowRunning())
			glfwDestroyWindow(mWindow);

		glfwTerminate();
	}

	GLContext* GLContext::Create()
	{
#if defined _WIN32
		return new GLWin32Context();
#else
		return nullptr;
#endif
	}

	int GLContext::Width() const
	{
		int w, h;
		glfwGetFramebufferSize(mWindow, &w, &h);
		return w;
	}

	int GLContext::Height() const
	{
		int w, h;
		glfwGetFramebufferSize(mWindow, &w, &h);
		return h;
	}

	void GLContext::SetWindow(void* windowID)
	{
		mWindow = (GLFWwindow*)windowID;
	}

	void* GLContext::GetWindow() const
	{
		return (void*)mWindow;
	}

	bool GLContext::IsWindowRunning()
	{
		return !glfwWindowShouldClose(mWindow);
	}

	bool GLContext::PollEvents()
	{
		glfwPollEvents();
		return true;
	}

	GLContext::~GLContext()
	{
		if (IsWindowRunning())
			glfwDestroyWindow(mWindow);
	}

	void* GLWin32Context::GetCurrentContext()
	{
		return (void*)wglGetCurrentContext();
	}

	void* GLWin32Context::GetCurrentDisplay()
	{
		return (void*)wglGetCurrentDC();
	}

	GLWin32Context::GLWin32Context()
	{

	}

}