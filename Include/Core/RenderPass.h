#pragma once

#include <Core/Camera.h>
#include <Core/Scene.h>
#include <Core/Camera.h>
#include <Core/RenderTarget.h>

namespace gcore
{
	class RenderPass
	{
	public:
		RenderPass();

		void SetScene(Scene* scene);

		Scene* GetScene() const;

		void SetCamera(Camera* camera);

		Camera* GetCamera() const;

		void SetRenderTarget(RenderTarget* renderTarget);

		RenderTarget* GetRenderTarget() const;

		void Draw();

		virtual ~RenderPass();

	protected:
		ScenePtr mScenePtr;
		CameraPtr mCameraPtr;
		RenderTargetPtr mRenderTargetPtr;
	};

	
	typedef std::shared_ptr<RenderPass> RenderPassPtr;
	typedef std::map<unsigned int, RenderPassPtr> RenderPassMap;
}