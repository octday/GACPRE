#include <Core/Node.h>

namespace gcore
{
	Node::Node()
	{

	}

	Node::~Node()
	{

	}

	void Node::AddRenderable(Renderable* renderable)
	{
		mRenderableList.push_back(RenderablePtr(renderable));
	}

	void Node::RemoveRenderable(unsigned int index)
	{
		if (index < mRenderableList.size())
		{
			auto iter = std::find(mRenderableList.begin(), mRenderableList.end(), mRenderableList.at(index));
			mRenderableList.erase(iter);
		}
	}

	void Node::RemoveRenderable(Renderable* renderable)
	{
		auto iter = std::find(mRenderableList.begin(), mRenderableList.end(), RenderablePtr(renderable));
		if (iter != mRenderableList.end())
		{
			mRenderableList.erase(iter);
		}
	}

	Renderable* Node::GetRenderable(unsigned int index) const
	{
		if (index < mRenderableList.size())
		{
			return mRenderableList.at(index).get();
		}
		else
		{
			return nullptr;
		}
	}

	void Node::CleanRenderable()
	{
		mRenderableList.clear();
	}

	unsigned int Node::GetRenderableCount() const
	{
		return mRenderableList.size();
	}

}