#include <Core/Renderable.h>
#include <Core/Device.h>

namespace gcore
{
	Renderable::Renderable()
	{

	}

	Renderable::~Renderable()
	{

	}

	void Renderable::SetVertexData(const Vec3List& vertexList, const Vec3List& normalList, const Vec4List& colorList, const std::vector<Vec2List>& texCoordListVec)
	{

	}

	void Renderable::SetIndexedVertexData(const UIntList& indexList, const Vec3List& vertexList, const Vec3List& normalList, const Vec4List& colorList, const std::vector<Vec2List>& texCoordListVec)
	{

	}

	void Renderable::Render(Device* device)
	{
		device->DrawPrimtives();
	}

}