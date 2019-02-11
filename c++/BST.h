#include <memory>
#include <utility>
#include <functional>
#include <iostream>
#include <vector>


template<class K, class V, class C = std::greater<K>>

class BST
{

private:
  // define basic block of a BST: node
  struct Node
  {
    std::pair<K,V> _pair;               // key and value stored in a single object
    std::unique_ptr<Node> _left;        // points to left child
    std::unique_ptr<Node> _right;       // points to right child
    Node* _parent;                      // ownership of a _parent node already retained
    Node(const std::pair<K,V>& pair,
      Node* parent) : _pair{pair}, _left{nullptr}, _right{nullptr}, _parent{parent} {}

    ~Node() = default;
  };

  std::unique_ptr<Node> root;
  C cfr;

  // a recursive function that adds a new key-value pair to the subtree born from Node* curr_node.
  // we use it as a helper function called inside bool insert(const std::pair<K,V>& pair)
  // passing the root as the Node* value.
  bool InsertPrivate(Node* curr_node, const std::pair<K,V>& pair);

public:

  BST() {root = nullptr;}
  class Iterator;
  class ConstIterator;

  // copy assignemnt
  BST<K,V,C>& operator=(const BST<K,V,C>& rhs)
  {
 	  clear();         // empty lhs tree from its current content
	  copy(rhs.root);  // call to helper function (starting from root node)
	   return *this;   // return a reference to the tree managed by root
  }

  // copy costructor
  BST<K,V,C>(const BST<K,V,C>& rhs) { copy(rhs.root); }

  // move costructor
  BST(BST<K,V,C>&& rhs)
  	: root{std::move(rhs.root)} {}

  // move assignment
  BST<K,V,C>& operator=(const BST&& rhs)
  {
  	root = std::move(rhs.root);
	  return *this;
  }

  Iterator begin();
  Iterator end() {return Iterator{nullptr};}

  ConstIterator begin() const;
  ConstIterator end() const {return ConstIterator{nullptr};}

  ConstIterator cbegin() const;
  ConstIterator cend() const {return ConstIterator{nullptr};}

  ConstIterator find(const K& item) const;

  bool insert(const std::pair<K,V>& pair);

  
  std::vector<std::pair<K, V>> fromBSTtoVector();
  
  void fromVectortoBalance(const std::vector<std::pair<K,V>>& nodi, int primo, int ultimo);
	
  void balance();
  


  // clear method
  void clear() { root.reset(); }

  // helper function used for copy constuctor/assignemnt
  void copy(const std::unique_ptr<Node>& curr_node);

  Iterator find(const K& key);


  template <class oK, class oV, class oC>

  friend std::ostream& operator<<(std::ostream&, const BST<oK,oV,oC>&);
};
