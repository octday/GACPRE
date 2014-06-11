#include "DXContext.h"
#include <iostream>

namespace gcore
{
	DXContext::DXContext()
		:mHwnd(0)
	{

	}

	void DXContext::Terminate()
	{

	}

	bool DXContext::MakeCurrent()
	{
		return true;
	}

	bool DXContext::UnMakeCurrent()
	{
		return true;
	}

	bool DXContext::SwapBuffers()
	{
		return true;
	}

	bool DXContext::SetSwapInterval(int interval)
	{
		return true;
	}

	void* DXContext::GetCurrentContext()
	{
		return nullptr;
	}

	void* DXContext::GetCurrentDisplay()
	{
		return nullptr;
	}

	bool DXContext::Init()
	{
		return true;
	}

	int DXContext::Width() const
	{
		RECT rect;
		GetClientRect(mHwnd, &rect);
		return rect.right;
	}

	int DXContext::Height() const
	{
		RECT rect;
		GetClientRect(mHwnd, &rect);
		return rect.bottom;
	}

	void DXContext::SetWindow(void* windowID)
	{
		mHwnd = (HWND)windowID;
	}

	void* DXContext::GetWindow() const
	{
		return (void*)mHwnd;
	}

	bool DXContext::IsWindowRunning()
	{
		return false;
	}

	bool DXContext::PollEvents()
	{
		return true;
	}

}