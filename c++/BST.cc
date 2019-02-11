#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "BST.h"

template<class K, class V, class C>
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

template<class K, class V, class C>
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

template <class K, class V, class C>
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


template<class K, class V, class C>
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

template<class K, class V, class C>
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

template<class K, class V, class C>
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
std::ostream& operator<<(std::ostream& os, const BST<K,V,C>& tree)
 {
	for (const auto& x : tree)
		os << "(" << x.first <<"," << x.second << ")" << "\n";
	return os;
}

template<class K, class V, class C>
void BST<K, V, C>::copy(const std::unique_ptr<Node>& curr_node)
{
	if(curr_node != nullptr) 			// check for a valid pointer
	{
		insert(curr_node -> _pair); // new node inserted
		copy(curr_node -> _left);   // recursive call on left node
		copy(curr_node -> _right);  // recursive call on right node
	}
}


template<class K, class V, class C>
std::vector<std::pair<K, V>> BST<K,V,C>::fromBSTtoVector(){
	std::vector<std::pair<K,V>> nodi_ordinati;
	for(auto const& nodo : *this){
		std::pair<K,V> coppia(nodo.first, nodo.second);
		nodi_ordinati.push_back(coppia);
	}

	return nodi_ordinati;
}

template<class K, class V, class C>
void BST<K,V,C>::fromVectortoBalance(const std::vector<std::pair<K,V>>& nodi, int primo, int ultimo){

	if(primo > ultimo){
		return;
	}

	int meta = (primo + ultimo) / 2;

	insert(nodi[meta]);
	fromVectortoBalance(nodi, primo, meta - 1);
	fromVectortoBalance(nodi, meta + 1, ultimo);
}

template<class K, class V, class C>
void BST<K, V, C>::balance()
{
	std::vector<std::pair<K,V>> vettore = this -> fromBSTtoVector();
	clear();
  fromVectortoBalance(vettore, 0, vettore.size() - 1);
}

template <class K, class V, class C>
typename BST<K,V,C>::Iterator BST<K,V,C>::find(const K& key)
{
  Node* n = root.get();

	while(n)
  {
    if(key < n->_pair.first)
    {
      n = n->_left.get();
    }
    else if (key > n->_pair.first)
    {
      n = n->_right.get();
    }
    else if (key == n->_pair.first)
    {
      return Iterator(n);
    }
  }
	std::cout << "The key " << key << " was not found in the tree.\n";
  return end();
}
