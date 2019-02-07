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
  
  BST( const BST& rhs ); // copy costructor
  BST& operator=(const BST& rhs) ; // copy assignment


  BST( const BST&& rhs ); // move costructor
  BST(const BST&& rhs); // move assignment
  ~BST();  //destructor
  
  // Dato il valore di una key la cerca all'interno dell'albero e ci restituisce
  // un iterator al nodo.
  ConstIterator find(const K& item) const;

  Iterator begin() const;

  ConstIterator cbegin() const;

  ConstIterator end() const;
  ConstIterator begin() const;

  

};

template <class T>
class BST<K, V>::Iterator : public std::iterator<std::forward_iterator_tag, T> {
  using Node = BST<K, V>::Node;

    Node* current;

     public:
       Iterator(Node* n) : current{n} {}
       Iterator(const Iterator&) = default;
       T& operator*() const { return current->val; }
       Iterator& operator++() {
       		current = current->next.get();
       		return *this;
       }
       
       Iterator operator++(int) {
		Iterator it{*this};
		++(*this);
		return it;
      }
      
      bool operator==(const Iterator& other) { return current == other.current; }
      bool operator!=(const Iterator& other) { return !(*this == other); }
					   
};
