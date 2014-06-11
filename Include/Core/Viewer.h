#pragma once

#include <Core\Context.h>
#include <Core\RenderPass.h>

namespace gcore
{
	class CORE_API Viewer
	{
	public:
		Viewer(bool fullScreen = false, const std::string& windowTitle = "GACPRE");

		Viewer(void* windowID);

		Context* GetContext();

		int Run();

		int GetWidth() const;

		int GetHeight() const;

		virtual ~Viewer();

	public:
		void Draw();

		void AddOrSetRenderPass(unsigned int index, RenderPass* renderPass);

		void RemoveRenderPass(unsigned int index);

		void CleanRenderPass();

		static int RenderThread(void* param);

	protected:
		Context* mContext;
		RenderPassMap mRenderPassMap;
	};
}