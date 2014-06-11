#include <Core/Scene.h>

namespace gcore
{
	Scene::Scene()
	{

	}

	Scene::~Scene()
	{

	}

	void Scene::AddNode(Node* node)
	{
		mNodeList.push_back(NodePtr(node));
	}

	void Scene::RemoveNode(unsigned int index)
	{
		if (index < mNodeList.size())
		{
			auto iter = std::find(mNodeList.begin(), mNodeList.end(), mNodeList.at(index));
			mNodeList.erase(iter);
		}
	}

	void Scene::RemoveNode(Node* node)
	{
		auto iter = std::find(mNodeList.begin(), mNodeList.end(), NodePtr(node));
		if (iter != mNodeList.end())
		{
			mNodeList.erase(iter);
		}
	}

	Node* Scene::GetNode(unsigned int index)
	{
		if (index < mNodeList.size())
		{
			return mNodeList.at(index).get();
		}
		else
		{
			return nullptr;
		}
	}

	void Scene::CleanNode()
	{
		mNodeList.clear();
	}

	void Scene::Render(Device* device)
	{
		for (size_t i = 0; i < mNodeList.size(); ++i)
		{
			NodePtr& node = mNodeList[i];
			for (size_t j = 0; j < node->GetRenderableCount(); ++j)
			{
				node->GetRenderable(j)->Render(device);
			}
		}
	}

}