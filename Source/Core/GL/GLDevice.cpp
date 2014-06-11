#include "GLDevice.h"
#include "GLTypeConverter.h"

namespace gcore
{
	GLDevice::GLDevice()
	{

	}

	GLDevice::~GLDevice()
	{

	}

	void GLDevice::SetIsEnableDepthTest(bool isEnable)
	{
		if (isEnable)
		{
			glEnable(GL_DEPTH_TEST);
		} 
		else
		{
			glDisable(GL_DEPTH_TEST);
		}
	}

	void GLDevice::CleanBuffers(const gbase::Vector4& color, double depth, int stencil)
	{
		glClearColor(color[0], color[1], color[2], color[3]);
		glClearDepth(depth);
		glClearStencil(stencil);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void GLDevice::DrawPrimtives()
	{

	}

	void GLDevice::SetViewport(int x, int y, int width, int height)
	{
		glViewport(x, y, width, height);
	}

	void GLDevice::SetDrawBuffers(const BufferTypeList& buffers)
	{
		if (mCacheDrawBuffers == buffers)
			return;

		std::vector<GLenum> glBuffers;
		size_t bufferCount = buffers.size();
		for (size_t i = 0; i < bufferCount; ++i)
		{
			GLenum buffer = GLTypeConverter::GetGLBufferType(buffers[i]);
			glBuffers.push_back(buffer);
		}
		
		if (!buffers.empty())
			glDrawBuffers(bufferCount, &glBuffers[0]);
	}

	void GLDevice::SetReadBuffer(BufferType buffer)
	{
		glReadBuffer(GLTypeConverter::GetGLBufferType(buffer));
	}

	void GLDevice::SetModelMatirx(const gbase::Matrix4& modelMatirx)
	{

	}

	void GLDevice::SetViewMatirx(const gbase::Matrix4& viewMatirx)
	{

	}

	void GLDevice::SetModelViewMatirx(const gbase::Matrix4& modelViewMatirx)
	{

	}

	void GLDevice::SetProjectionMatirx(const gbase::Matrix4& projMatrix)
	{

	}

	void GLDevice::SetModelViewProjectionMatirx(const gbase::Matrix4& modelViewProjMatrix)
	{

	}

}