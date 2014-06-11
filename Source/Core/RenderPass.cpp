#include <Core/RenderPass.h>
#include <Core/Device.h>

namespace gcore
{

	void RenderPass::Draw()
	{
		Device* device = Device::Instance();
		mRenderTargetPtr->BeginDraw(device);
		mScenePtr->Render(device);
		mRenderTargetPtr->EndDraw(device);
	}

	void RenderPass::SetScene(Scene* scene)
	{
		mScenePtr = ScenePtr(scene);
	}

	Scene* RenderPass::GetScene() const
	{
		return mScenePtr.get();
	}

	void RenderPass::SetCamera(Camera* camera)
	{
		mCameraPtr = CameraPtr(camera);
	}

	Camera* RenderPass::GetCamera() const
	{
		return mCameraPtr.get();
	}

	void RenderPass::SetRenderTarget(RenderTarget* renderTarget)
	{
		mRenderTargetPtr = RenderTargetPtr(renderTarget);
	}

	RenderTarget* RenderPass::GetRenderTarget() const
	{
		return mRenderTargetPtr.get();
	}

	RenderPass::RenderPass()
	{

	}

	RenderPass::~RenderPass()
	{

	}

}