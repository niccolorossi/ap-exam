#include <memory>

template<typename K, typename V, typename C = std::greater<K>>
class BST
{

private:
// define basic block of a BST: node
  struct Node
  {
    K key;
    V value;
    std::unique_ptr<Node> _left;
    std::unique_ptr<Node> _right;
    Node* parent;
    Node(const K& key, const V& value, Node* left, Node* right,
    Node* parent) : key{key}, value{value}, _left{left}, _right{right}, _parent{parent} {}
    ~Node() = default;
  };

  std::unique_ptr<Node> root;
  C cfr;
	
public:

  BST() {root = nullptr;}
  class Iterator;
  class ConstIterator;
  
  BST( const BST<K, V, C>& rhs ){
  	if(rhs.root) copy(*rhs.root);
  } // copy costructor
  
BST<K, V, C>& operator=(const BST<K, V, C>& rhs){
  	if(!rhs.root) root.reset();
	else {
		i:x
		f(root) clear();
		copy(*rhs.root);
	}
	return *this;
  } // copy assignment


  BST(BST<K, V, C>&& rhs ) noexcept: root{std::move(rhs.root)} {} // move costructor
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
  
  
  //è la funzione ricorsiva che si trova su tutti i libri. ha il problema di aver 
  //bisogno di un pointer ad un nodo come argomento iniziale. Per cui si puo usarla 
  // chiamandola all'interno di un'altra funzione Insert. 
  bool insert(Node* curr_node, const K& key, const V& value);

  bool Insert(const K& key, const V& value);

  

  
};
template<typename K, typename V, typename C>
class Iterator : public std::iterator<std::biderectional_iterator_tag, K> {
	public: 
		Iterator();:x

		
		BST<>
		//operatore di confronto.
		bool operator==(const Iterator& rhs) const;

		bool operator!=(const Iterator& rhs) const;
		
		// operatore di dereference. ritorna una reference al valore puntato
		const K& operator*() const;

		//preincrement. si sposta al prossimo valore più grande
		Iterator operator++();

		//postincrement

};

 

