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
    Node(const std::pair<K,V>& pair, Node* left, Node* right,
         Node* parent) : _pair{pair}, _left{left}, _right{right}, _parent{parent} {}

    ~Node() = default;
  };

  std::unique_ptr<Node> root;
  C cfr;
	
public:

  BST() {root = nullptr;}
  class Iterator;
  class ConstIterator;
  
  BST( const BST<K, V, C>& rhs );// copy costructor
 

  BST(BST<K, V, C>&& rhs ) // move costructor
  BST(const BST&& rhs); // move assignment
  ~BST();  //destructor
  
  // Dato il valore di una key la cerca all'interno dell'albero e ci restituisce
  // un iterator al nodo.
  ConstIterator find(const K& item) const;

  Iterator begin() const;

  ConstIterator cbegin() const;

  ConstIterator end() const;
  ConstIterator begin() const;
  
 
  //è la funzione ricorsiva che si trova su tutti i libri. ha il problema di aver 
  //bisogno di un pointer ad un nodo come argomento iniziale. Per cui si puo usarla 
  // chiamandola all'interno di un'altra funzione Insert. 
  bool insert(Node* curr_node, const K& key, const V& value);

  bool Insert(const K& key, const V& value);

  

  
};


 

