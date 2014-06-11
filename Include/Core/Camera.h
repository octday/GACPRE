#pragma once

#include <Core\Core.h>
#include <Base\Matrix.h>

namespace gcore
{
	class CORE_API Camera
	{
	public:
		Camera();

		~Camera();

		void SetPosition(const gbase::Vector3& position);

		const gbase::Vector3& GetPosition() const;

		void SetUp(const gbase::Vector3& up);

		const gbase::Vector3& GetUp() const;

		void SetLook(const gbase::Vector3& look);

		const gbase::Vector3& GetLook() const;

		void SetNear(float near);

		float GetNear() const;

		void SetFar(float far);

		float GetFar() const;

		void SetFov(float fov);

		float GetFov() const;

		void SetAspect(float aspect);

		float GetAspect() const;

		const gbase::Matrix4& GetViewMatrix();

		const gbase::Matrix4& GetProjectionMatrix();

		const gbase::Matrix4& GetViewProjectionMatrix();

	protected:
		void UpdateView();
		void UpdateFrustum();
		void UpdateViewAndFrustum();

		gbase::Vector3 mPosition;
		gbase::Vector3 mLook;
		gbase::Vector3 mUp;
		gbase::Vector3 mRight;
		float mNear;
		float mFar;
		float mFov;
		float mAspect;
		gbase::Matrix4 mCacheViewMatrix;
		gbase::Matrix4 mCacheProjMatrix;
		gbase::Matrix4 mCacheViewProjMatrix;
	};

	typedef std::shared_ptr<Camera> CameraPtr;
}