#pragma once

#include <Core\State.h>
#include <Base\Vector.h>

namespace gcore
{
	typedef std::vector<gbase::Vector4> Vec4List;
	typedef std::vector<gbase::Vector3> Vec3List;
	typedef std::vector<gbase::Vector2> Vec2List;
	typedef std::vector<unsigned int> UIntList;

	class Device;

	class CORE_API Renderable
	{
	public:
		Renderable();

		virtual ~Renderable();

		void SetVertexData(const Vec3List& vertexList, const Vec3List& normalList, const Vec4List& colorList,
			const std::vector<Vec2List>& texCoordListVec);

		void SetIndexedVertexData(const UIntList& indexList, const Vec3List& vertexList, const Vec3List& normalList, 
			const Vec4List& colorList, const std::vector<Vec2List>& texCoordListVec);

	public:
		void Render(Device* device);
	};

	typedef std::shared_ptr<Renderable> RenderablePtr;
	typedef std::vector<RenderablePtr> RenderablePtrList;
}