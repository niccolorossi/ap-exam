#include <memory>
#include <utility>

template<class K, class V>
class BST
{

private:
  // define basic block of a BST: node
  struct Node
  {
    std::pair<K,V> _pair;               // key and value stored in a single object
    std::unique_ptr<Node> _left;        // point to left and right child respectively
    std::unique_ptr<Node> _right;
    Node* _parent;                      // a parent node is not owned by a single object
    Node(const K& key, const V& value, const Node* left, const Node* right,
    const Node* parent) : _pair{pair(key,value)}, _left{left}, _right{right}, _parent{parent} {}
    ~Node() = default;
  };

  std::unique_ptr<Node> root;

public:

  BST() {root = nullptr;}
  class Iterator;
  class ConstIterator;

};
