#include <memory>
#include <utility>
#include <functional>
#include <iostream>

template<typename K, typename V, typename C = std::greater<K>>
class BST
{

private:
  // define basic block of a BST: node
  struct Node
  {
    std::pair<K,V> _pair;               // key and value stored in a single object
    std::unique_ptr<Node> _left;        // points to left child
    std::unique_ptr<Node> _right;       // points to right child
    Node* _parent;                      // a parent node is is pointed by more than an obj (hence not unique)
    Node(const std::pair<K,V>& pair,
      Node* parent) : _pair{pair}, _left{nullptr}, _right{nullptr}, _parent{parent} {}

    ~Node() = default;
  };

  std::unique_ptr<Node> root;
  C cfr;                                                              // ?

  // a recursive function that adds a new key-value pair to the subtree born from Node* curr_node.
  // we use it as a helper function called inside bool insert(const std::pair<K,V>& pair)
  // passing the root as the Node* value.
  bool InsertPrivate(Node* curr_node, const std::pair<K,V>& pair);

public:

  BST() {root = nullptr;}
  class Iterator;
  class ConstIterator;



  BST (const BST<K,V,C>& rhs);   // cpy ctor
  BST& operator=(const BST<K,V,C>& rhs);   // copy assignement

  BST(BST<K,V,C>&& rhs) : root{move(rhs->root.get())} {}  // move costructor

  BST& operator=(const BST&& rhs){

    root.reset();
    root = move(rhs->root.get());
    return *this;

  };         // move assignment

  Iterator begin();
  Iterator end() {return Iterator{nullptr};}

  ConstIterator begin() const;
  ConstIterator end() const {return ConstIterator{nullptr};}

  ConstIterator cbegin() const;
  ConstIterator cend() const {return ConstIterator{nullptr};}

  ConstIterator find(const K& item) const;          // ? poi metto mia

  bool insert(const std::pair<K,V>& pair);

  void clear() {root.reset();}

  template <class oK, class oV, typename oC>
  friend std::ostream& operator<<(std::ostream&, const BST<oK,oV,oC>&);

  void Copy(Node *c);



  void balance(BST<K,V> tree);

  void balanceUtil(std::vector<std::pair<K, V>>& nodes, int start, int end);


};
