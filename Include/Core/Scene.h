#pragma once

#include <Core\Node.h>
#include <Core\Light.h>

namespace gcore
{
	class Device;

	class CORE_API Scene
	{
	public:
		Scene();

		void AddNode(Node* pNode);

		void RemoveNode(unsigned int index);

		void RemoveNode(Node* node);

		Node* GetNode(unsigned int index);

		void CleanNode();

		virtual ~Scene();

		void Render(Device* device);

	protected:
		NodePtrList mNodeList;
	};

	typedef std::shared_ptr<Scene> ScenePtr;
}