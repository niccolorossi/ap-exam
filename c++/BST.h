#include <memory>

template<class K, class V>
class BST
{

private:
// define basic block of a BST: node
  struct Node
  {
    K key;
    V value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    Node* parent;
    Node(const K& key, const V& value, Node* left, Node* right,
    Node* parent) : key{key}, value{value}, left{left}, right{right}, parent{parent} {}
    ~Node() = default;
  };

  std::unique_ptr<Node> root;

public:

  BST() {root = nullptr;}
  class Iterator;
  class ConstIterator;

};
