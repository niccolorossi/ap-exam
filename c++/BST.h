#include <memory>
#include <utility>
#include <functional>
#include <iostream>
#include <vector>
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
  BST<K,V,C>& operator=(const BST<K,V,C>& rhs){
 	clear(); // svuota l'albero a sinistra dell'uguale del suo attuale contenuto.
	copy(rhs.root); // utilizziamo la funzione copy(ricorsiva) a partire dalla radice del nodo
	return *this; // ritorniamo una reference al root node 
  }
     // copy costructor
  BST<K,V,C>(const BST<K,V,C>& rhs){copy(rhs.root);} // copy assignemnt

  BST(BST<K,V,C>&& rhs)
  	:root{std::move(rhs.root)} {}        // move costructor
  BST<K,V,C>& operator=(const BST&& rhs){
  	root = std::move(rhs.root);
	return *this;
  }// move assignment

  Iterator begin();
  Iterator end() {return Iterator{nullptr};}

  ConstIterator begin() const;
  ConstIterator end() const {return ConstIterator{nullptr};}

  ConstIterator cbegin() const;
  ConstIterator cend() const {return ConstIterator{nullptr};}

  ConstIterator find(const K& item) const;

  bool insert(const std::pair<K,V>& pair);
  //clear method
  void clear() {root.reset();}
   
  void copy(const std::unique_ptr<Node>& curr_node); // funzione ricorsiva. passiamo uno unique_ptr perchè root, _right e _left lo sono
  
  std::vector<std::pair<K, V>> fromBSTtoVector();

  template <class oK, class oV, typename oC>
  friend std::ostream& operator<<(std::ostream&, const BST<oK,oV,oC>&);
};
