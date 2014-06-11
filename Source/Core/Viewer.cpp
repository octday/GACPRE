#include <Core/Viewer.h>
#include <Core/Configuration.h>
#include "GL/GLContext.h"
#include "DX/DXContext.h"

namespace gcore
{
	int Viewer::RenderThread(void* param)
	{
		Viewer* viewer = (Viewer*)param;

		Context* context = viewer->GetContext();
		while (context->IsWindowRunning())
		{
			viewer->Draw();
			context->PollEvents();
		}

		context->Terminate();
		return 0;
	}

	Viewer::Viewer(bool fullScreen, const std::string& windowTitle)
		: mContext(nullptr)
	{
		Context* context = GetContext();

		void* window = nullptr;
		if (Configuration::Instance()->GetGraphicsAPI() == Configuration::OPENGL)
		{
			GLFWwindow* glWindow = nullptr;
			if (!glfwInit())
				return;

			glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
			glWindow = glfwCreateWindow(1200, 800, windowTitle.c_str(), NULL, NULL);
			if (glWindow == nullptr)
			{
				context->Terminate();
				return;
			}

			window = (void*)glWindow;
			
		}
		else
		{
			return;
		}

		context->SetWindow(window);
		context->MakeCurrent();

		if (!context->Init())
			return;

		RenderPass* defaultRenderPass = new RenderPass();
		defaultRenderPass->SetScene(new Scene());
		defaultRenderPass->SetCamera(new Camera());

		BackBufferTarget* rendertarget = new BackBufferTarget(GetContext());
		rendertarget->SetBackgroundColor(gbase::GrayColor);

		defaultRenderPass->SetRenderTarget(rendertarget);
		AddOrSetRenderPass(0U, defaultRenderPass);
		

		
		//std::thread renderThread(&Viewer::RenderThread, this);
	}

	Viewer::Viewer(void* windowID)
		: mContext(nullptr)
	{

	}

	Viewer::~Viewer()
	{
		CleanRenderPass();

		if (mContext != nullptr)
			delete mContext;
	}

	int Viewer::Run()
	{
		Context* context = GetContext();

		if (Configuration::Instance()->GetGraphicsAPI() == Configuration::OPENGL)
		{
			GLFWwindow* window = (GLFWwindow*)context->GetWindow();
			glfwShowWindow(window);
		}
		else
		{


		}

		Viewer::RenderThread(this);

		return 1;
	}

	Context* Viewer::GetContext()
	{
		if (mContext == nullptr)
		{
			if (Configuration::Instance()->GetGraphicsAPI() == Configuration::OPENGL)
			{
				mContext = GLContext::Create();
			}
			else
			{
				mContext = new DXContext();
			}
		}
		
		return mContext;
	}

	void Viewer::Draw()
	{
		for (auto iter = mRenderPassMap.begin(); iter != mRenderPassMap.end(); ++iter)
		{
			iter->second->Draw();
		}

		float ratio;
		int width = GetWidth();
		int height = GetHeight();
		ratio = width / (float)height;        
		glViewport(0, 0, width, height);        
		glClear(GL_COLOR_BUFFER_BIT);        
		glMatrixMode(GL_PROJECTION);        
		glLoadIdentity();        
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);        
		glMatrixMode(GL_MODELVIEW);        
		glLoadIdentity();        
		glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);        
		glBegin(GL_TRIANGLES);        
		glColor3f(1.f, 0.f, 0.f);        
		glVertex3f(-0.6f, -0.4f, 0.f);        
		glColor3f(0.f, 1.f, 0.f);        
		glVertex3f(0.6f, -0.4f, 0.f);        
		glColor3f(0.f, 0.f, 1.f);        
		glVertex3f(0.f, 0.6f, 0.f);       
		glEnd();
	}

	int Viewer::GetWidth() const
	{
		return mContext->Width();
	}

	int Viewer::GetHeight() const
	{
		return mContext->Height();
	}

	void Viewer::AddOrSetRenderPass(unsigned int index, RenderPass* renderPass)
	{
		mRenderPassMap[index] = RenderPassPtr(renderPass);
	}

	void Viewer::RemoveRenderPass(unsigned int index)
	{
		mRenderPassMap.erase(index);
	}

	void Viewer::CleanRenderPass()
	{
		mRenderPassMap.clear();
	}

}