#include <Core/Camera.h>

namespace gcore
{
	Camera::Camera()
		:mPosition(gbase::Vector3(0.0f, 0.0f, 0.0f))
		, mLook(gbase::Vector3(0.0f, 1.0f, 0.0f))
		, mUp(gbase::Vector3(0.0f, 0.0f, 1.0f))
		, mRight(gbase::Vector3(1.0f, 0.0f, 0.0f))
		, mNear(0.1f)
		, mFar(1000.0f)
		, mFov(30.0f)
		, mAspect(1.5f)
	{

	}

	Camera::~Camera()
	{

	}

	void Camera::SetPosition(const gbase::Vector3& position)
	{
		mPosition = position;
	}

	const gbase::Vector3& Camera::GetPosition() const
	{
		return mPosition;
	}

	void Camera::SetUp(const gbase::Vector3& up)
	{
		mUp = up;
	}

	const gbase::Vector3& Camera::GetUp() const
	{
		return mUp;
	}

	void Camera::SetLook(const gbase::Vector3& look)
	{
		mLook = look;
	}

	const gbase::Vector3& Camera::GetLook() const
	{
		return mLook;
	}

	void Camera::SetNear(float near)
	{
		mNear = near;
	}

	float Camera::GetNear() const
	{
		return mNear;
	}

	void Camera::SetFar(float far)
	{
		mFar = far;
	}

	float Camera::GetFar() const
	{
		return mFar;
	}

	void Camera::SetFov(float fov)
	{
		mFov = fov;
	}

	float Camera::GetFov() const
	{
		return mFov;
	}

	const gbase::Matrix4& Camera::GetViewMatrix()
	{
		UpdateView();
		return mCacheViewMatrix;
	}

	const gbase::Matrix4& Camera::GetProjectionMatrix()
	{
		UpdateFrustum();
		return mCacheProjMatrix;
	}

	const gbase::Matrix4& Camera::GetViewProjectionMatrix()
	{
		UpdateViewAndFrustum();
		return mCacheViewProjMatrix;
	}

	void Camera::SetAspect(float aspect)
	{
		mAspect = aspect;
	}

	float Camera::GetAspect() const
	{
		return mAspect;
	}

	void Camera::UpdateView()
	{
		mCacheViewMatrix = gbase::Lookat(mPosition, mPosition + mLook, mUp);
	}

	void Camera::UpdateFrustum()
	{
		mCacheProjMatrix = gbase::Perspective(mFov, mAspect, mNear, mFar);
	}

	void Camera::UpdateViewAndFrustum()
	{
		UpdateView();
		UpdateFrustum();
		mCacheViewProjMatrix = mCacheViewMatrix * mCacheProjMatrix;
	}

}