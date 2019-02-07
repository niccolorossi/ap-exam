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
  
  const K& findMin( ) const;

  const K& findMax( ) const;

  bool contains( const V& v) const;
	
 
  //Controlla se l'albero è vuoto o meno.	
  bool isEmpty() const {return root == nullptr; }
  
  // Stampa l'albero (da inserire quindi anche metodo per ordinarlo)

  void printTree() const;

  // svuota l'albero

  void MakeEmpty( );
  
  
  //inserisce un nuovo nodo all'interno dell'albero	
  void insert(const K& key, const V& value);

  
};



