#include <iostream>
#include <memory>
#include <utility>

#include "BST.h"

template <class K, class V>
class BST<K,V>::Iterator : public std::iterator<std::forward_iterator_tag, V>
{
using Node = BST<K,V>::Node;
  Node* current;

public:
  Iterator() {current = nullptr;}
  Iterator(Node* n) : current{n} {}
  Iterator(const Iterator&) = default;                    // copy ctor deleted
  V& operator*() const { return current->_pair.first; }   // dereference operator

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

template <class K, class V>
class BST<K,V>::ConstIterator : public BST<K,V>::Iterator
{
 public:

  using parent = BST<K,V>::Iterator;
  using parent::Iterator;
  const V& operator*() const { return parent::operator*(); }

};
