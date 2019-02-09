#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "BST.h"

template<typename K, typename V, typename C>
bool BST<K,V,C>::InsertPrivate(Node* curr_node, const std::pair<K,V>& pair)
{
	// by means of the templated operator we compare the key we want to insert and
	// the key contained in curr_node. As a default value for C we set std::greater<K>
	// hence the templated operator works like <
	if(cfr(curr_node->_pair.first, pair.first))
	{
		// Argument key is smaller than current node key. We move left, therefore either:
		// 1) curr_node has no left child -> we create a new Node
		// 2) curr_node has a left child ->  recursive call to function
		if(!curr_node -> _left)
		{
			// A new node is created via std::unique_ptr::reset().
			// This deletes the memory which was previously managed
			// and, instead, assigns a new value to the pointer
			curr_node -> _left.reset(new Node(pair, curr_node));
		}
		else
		{
		// std::unique_ptr::get() returns a pointer to the managed memory
		InsertPrivate(curr_node->_left.get(), pair);
		}
	}
	else if (cfr(pair.first, curr_node -> _pair.first))
	{
		if(!curr_node -> _right)
		{
			curr_node -> _right.reset(new Node(pair, curr_node));
		}
		else
		{
			InsertPrivate(curr_node -> _right.get(), pair);
		}
	}

	else return false; // if key is already present it returns false

	return true; 			 // if a new key is added correctly returns true
}

template<typename K, typename V, typename C>
bool BST<K, V, C>::insert(const std::pair<K,V>& pair)
{
 	// initializes root if tree is empty
	if(!root)
	{
		// first node is inserted via std::unique_ptr::get()
		// the _parent pointer is nullptr for root
		root.reset(new Node(pair, nullptr));
		return true;
	}
	else
	{
		// ...InsertPrivate is called; ptr obtained via std::unique_ptr::get()
		return InsertPrivate(root.get(), pair);
	}
}

template <class K, class V, typename C>
class BST<K,V,C>::Iterator : public std::iterator<std::forward_iterator_tag, K>
{
using Node = BST<K,V,C>::Node;
  Node* current;

public:
  Iterator() {current = nullptr;}
  Iterator(Node* n) : current{n} {}
  Iterator(const Iterator&) = default;                    // copy ctor deleted
  std::pair<K,V>& operator*() const { return current->_pair; }   // dereference operator

  Iterator& operator++()                                   // increment operator
  {
    if (current->_right)
    {
      current = current->_right.get();
      while (current->_left)
      {
        current = current->_left.get();
      }
    }
    else
    {
      Node* aux{current->_parent};
			while(aux && (current == aux->_right.get()))
			{
				current = aux;
				aux = aux->_parent;
			}
			current = aux;
    }
    return *this;
  }

  bool operator==(const Iterator& other) { return current == other.current; }
  bool operator!=(const Iterator& other) { return !(*this == other); }

};

template <class K, class V, typename C>
class BST<K,V,C>::ConstIterator : public BST<K,V,C>::Iterator
{
 public:

  using parent = BST<K,V,C>::Iterator;
  using parent::Iterator;
  const std::pair<K,V>& operator*() const { return parent::operator*(); }

};


template<typename K, typename V, typename C>
class BST<K,V,C>::Iterator BST<K,V,C>::begin()
{

	if (root == nullptr)
	{
	return end();
	}
	Node* first_node = root.get();

	while (first_node->_left != nullptr)
	{

		first_node = first_node->_left.get();


	}
	return Iterator{first_node};
}

template<typename K, typename V, typename C>
class BST<K,V,C>::ConstIterator BST<K,V,C>::begin() const
{


	if (root == nullptr)
	{
		return end();
	}

	Node* first_node = root.get();
	while (first_node->_left != nullptr)
	{
		first_node = first_node->_left.get();
	}

	return ConstIterator{first_node};
}

template<typename K, typename V, typename C>
class BST<K,V,C>::ConstIterator BST<K,V,C>::cbegin() const
{

	if (root == nullptr)
	{
		return end();
	}

	Node* first_node = root.get();
	while (first_node->_left != nullptr)
	{
		first_node = first_node->_left.get();

	}

	return ConstIterator{first_node};
}


template <class K, class V, class C>
std::ostream& operator<<(std::ostream& os, const BST<K,V,C>& tree) {

	for(auto& x:tree)

	os << "(" << x.first <<"," << x.second << ")" << "\n";

	return os;

}

template<class K,class V, class C>
BST<K,V,C>& BST<K,V,C>::operator=(const BST& rhs)
{
    if(this != &rhs)
    {
        this->clear();
        Node *c = rhs.root.get();
        Copy(c);
    }
    return *this;
}


template<class K,class V, class C>
BST<K,V,C>::BST(const BST& rhs){

	Copy(rhs.root.get());

}


template<class K,class V, class C>
void BST<K,V,C>::Copy(Node *c)
{
    if (c != nullptr)
    {
        this->insert(c->_pair);
        Copy(c->_left.get());
        Copy(c->_right.get());
    }
}

template<class K,class V, class C>
void BST<K,V,C>::balance(BST<K,V> tree){



	 std::vector<std::pair<K, V>> pairVec;


	 for(const auto& x: tree)
	 {
			 pairVec.push_back(x);
	 }

	balanceUtil(pairVec, 0, pairVec.size()-1 );


}

template<class K,class V, class C>
void BST<K,V,C>::balanceUtil(std::vector<std::pair<K, V>>& pairVec, int start, int end){

      if (start > end) return;

      int mid = (start + end)/2;

      insert(pairVec[mid]);
      balanceUtil(pairVec, start, mid-1);
      balanceUtil(pairVec, mid+1, end);

}
