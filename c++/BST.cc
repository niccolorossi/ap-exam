#include "BST.h"



template<class K, class V>
typename BST<K, V>::Iterator&
BST<K, V>::Iterator:.operator++ ()
{
	Node *p;

	if (nodePtr == nullptr)
	{
		nodePtr = tree -> root;

		if(nodePtr == nullptr)
			throw EmptyTreeError{};

		while(nodePtr -> left != nullptr) {
			nodePtr = nodePtr -> left;
		}
	} else {
		if(nodePtr -> right != nullptr)
		{
			nodePtr = nodePtr -> right;

			while(nodePtr -> left != nullPtr) {
				nodePtr = nodePtr -> left;
			}
		} else {
			p = nodePtr -> parent;
			while( p != nullptr && nodePtr == p-> right)
			{
				nodePtr = p;
				p = p -> parent;
			}

			nodePtr = p;

		}
	}

	return *this;
}
