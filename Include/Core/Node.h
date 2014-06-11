#pragma once

#include <Core\Renderable.h>

namespace gcore
{
	class CORE_API Node
	{
	public:
		Node();

		void AddRenderable(Renderable* renderable);

		void RemoveRenderable(unsigned int index);

		void RemoveRenderable(Renderable* renderable);

		Renderable* GetRenderable(unsigned int index) const;

		unsigned int GetRenderableCount() const;

		void CleanRenderable();

		virtual ~Node();

	protected:
		RenderablePtrList mRenderableList;
	};

	typedef std::shared_ptr<Node> NodePtr;
	typedef std::vector<NodePtr> NodePtrList;
}