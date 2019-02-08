#include <iostream>
#include <memory>
#include <utility>

#include "BST.h"

template <class K, class V, typename C>
class BST<K,V, C>::Iterator : public std::iterator<std::forward_iterator_tag, V>
{
using Node = BST<K,V,C>::Node;
  Node* current;

public:
  Iterator() {current = nullptr;}
  Iterator(Node* n) : current{n} {}
  Iterator(const Iterator&) = default;                    // copy ctor deleted
  V& operator*() const { return current->_pair.second; }   // dereference operator

  Iterator& operator++()                                  // increment operator
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
  const V& operator*() const { return parent::operator*(); }

};

template <class K, class V, typename C>
void BST<K,V,C>::insert(const std::pair<K,V>& pair)
{
  if (root == nullptr)                 // if tree is empty
  {
    root.reset(new Node{pair, nullptr});
  }
  else
  {
    auto aux = root.get();
    while(aux)
    {
      if(pair.first < aux->_pair.first)
      {
        if(aux->_left)
        {
          aux = aux->_left.get();
        }
        else
        {
          aux->_left.reset(new Node{pair,aux});
          aux = nullptr;
        }
      }
      else if (pair.first > aux->_pair.first)
      {
        if(aux->_right)
        {
          aux = aux->_right.get();
        }
        else
        {
          aux->_right.reset(new Node{pair,aux});
          aux = nullptr;
        }
      }
      else if (pair.first == aux->_pair.first)
      {
        std::cout << "The key " << pair.first << " has already been inserted in the tree.\n";
      }

    }
  }
}
