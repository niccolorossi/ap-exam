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
    std::unique_ptr<Node> _left;        // points to left child
    std::unique_ptr<Node> _right;       // points to right child
    Node* _parent;                      // a parent node is is pointed by more than an obj (hence not unique)
    Node(const std::pair<K,V>& pair, Node* left, Node* right,
         Node* parent) : _pair{pair}, _left{left}, _right{right}, _parent{parent} {}
    ~Node() = default;
  };

  std::unique_ptr<Node> root;

public:

  BST() {root = nullptr;}
  class Iterator;
  class ConstIterator;

};
