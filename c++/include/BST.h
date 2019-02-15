/**
 * @file   BST.h
 * @brief  Header file for our Advanced Programming final project
 * @author Niccolò Rossi, Nicola Meneghini and Lorenzo Fresco
 */

#include <memory>
#include <utility>
#include <functional>
#include <iostream>
#include <vector>

#ifndef BST_H__
#define BST_H__

/**
 * @brief This class implements a simple Binary Search Tree
 *
 * @tparam K is the typename of the key
 * @tparam V is the typename of the value
 * @tparam C is the typename of the operator used to compare different keys
 *
 *
 **/

template<class K, class V, class C = std::greater<K>>
class BST
{

private:
  /**
   * @brief struct that implements one node of the tree
   *
   * Each node stores a pair composed of a key and a value. Each node can have
   * at most 2 children (one left and one right). We store also for every node
   * the parent.
   *
   * @tparam K is the typename of the key
   * @tparam V is the typename of the value
   * @tparam C is the operator used to compare two different keys
   */
  struct Node
  {
    /** Key and value are stored in a single std::pair object */
    std::pair<K,V> _pair;
    /** pointer to the left child */
    std::unique_ptr<Node> _left;
    /** pointer to the right child */
    std::unique_ptr<Node> _right;
    /** pointer to the parent node */
    Node* _parent;

    /** constructor for a new Node object */
    Node(const std::pair<K,V>& pair,
      Node* parent) : _pair{pair}, _left{nullptr}, _right{nullptr}, _parent{parent} {}
    /** default destructor */
    ~Node() = default;
  };
  /** pointer to the root of the tree */
  std::unique_ptr<Node> root;
  /** comparison operator */
  C cfr;

  /**
   * @brief Supplementary function that adds a node in a given subtree
   *
   *
   * A recursive function that adds a new key-value pair to the subtree. Given a current node
   * passed as argument it compares the new key passed with the key of the current
   * node. If it is smaller and the current node doesn't have a left child a node is
   * created and set as left child of the current node. If it has a child the function
   * is called recursevly on the left child. The same thing is done if the key is
   * bigger with the right child. It returns true in case of a correct insertion and
   * false in case of a duplicated node
   *
   *
   * @param curr_node a pointer to the node that we need for key comparison
   * @param pair the key-value pair that we want to insert in the tree
   *
   */
  bool InsertPrivate(Node* curr_node, const std::pair<K,V>& pair);

  /**
   * @brief Supplementary function used to create a deep copy of a tree
   *
   * This function is called by both the copy constructor and the copy assignemnt
   * functions. To perform a deep copy we add a node with the same value as the one
   * of the current node to a tree and then, if children are present, we call the
   * function on the children of the current node
   *
   * @param curr_node a pointer to the current node
   */
  void copy(const std::unique_ptr<Node>& curr_node);

  /**
   * @brief Auxiliary function used in the balance function
   *
   * Given a BST object the function returns a vector of pairs key-value in order.
   *
   *
   */
   std::vector<std::pair<K, V>> fromBSTtoVector();

  /**
   * @brief Auxiliary function used in the balance routine
   *
   * It creates a BST starting from an ordered vector. It starts by setting the
   * middle element of the vector as root and then calls the function recursevly
   * on the left and right halves of the vector
   *
   * @param nodi is the ordered pairs vector
   * @param primo the index of the first element
   * @param ultimo the index of the last element
   */
  void fromVectortoBalance(const std::vector<std::pair<K,V>>& nodi, int primo, int ultimo);

public:

  /**constructor of a new BST object */
  BST() { root = nullptr; }
  /**destructor */
  ~BST() { clear(); }

  class Iterator;
  class ConstIterator;

 /**
  * @brief Copy assignment
  *
  * @param rhs the tree that we want to copy from
  */
  BST<K,V,C>& operator=(const BST<K,V,C>& rhs)
  {
 	  clear();         // empty lhs tree from its current content
	  copy(rhs.root);  // call to helper function (starting from root node)
	  return *this;    // return a reference to the tree managed by root
  }

  /**
   * @brief Copy costructor
   *
   * @param rhs the tree that we want to use for initialization
   */
  BST<K,V,C>(const BST<K,V,C>& rhs) { copy(rhs.root); }

  /**
   * @brief Move costructor
   *
   * @param rhs the tree that we need to move
   */
  BST<K,V,C>(BST<K,V,C>&& rhs)
  	: root{std::move(rhs.root)} {}

  /**
   * @brief Move assignment
   *
   * @param the tree that we want to move
   */
  BST<K,V,C>& operator=(BST&& rhs)
  {
  	root = std::move(rhs.root);
	  return *this;
  }

  /**
   * @brief Returns an Iterator to the first in order node of the tree
   */
  Iterator begin();

  /**
   * @brief Returns a pointer to the end of the tree, indicated by nullptr
   */
  Iterator end() {return Iterator{nullptr};}

  /**
   * @brief Returns a const iterator to the first node
   */
  ConstIterator begin() const;

  /**
   * @brief Returns a const iterator to the last node
   */
  ConstIterator end() const {return ConstIterator{nullptr};}

  ConstIterator cbegin() const;
  ConstIterator cend() const {return ConstIterator{nullptr};}


  /**
   * @brief Given a key value, it returns an Iterator to a node in the tree
   *
   * @param item the key value that we want to look up
   */
  ConstIterator find(const K& item) const;

  /**
   * @brief Inserts a new node in the tree
   *
   * If the node is the first one to be inserted it is set as the root of the tree.
   *
   * @param pair the key-value pair that we want to insert in our tree
   *
   *
   */
  bool insert(const std::pair<K,V>& pair);

  /**
   * @brief Creates a balanced BST starting from an unbalanced one
   */
  void balance();

  /**
   * @breif Clears the current content of a given BST object
   */
  void clear() { root.reset(nullptr); }

  /**
   * @brief non const version of the find function
   *
   *
   */
  Iterator find(const K& key);

  /**
   * @brief Overload of the operator <<
   *
   * @param os the std::ostream where to print the result
   * @param bst the BST object we want to print
   */
  V& operator[](const K& key);
  const V& operator [](const K& key) const;
  template <class oK, class oV, class oC>
  friend std::ostream& operator<<(std::ostream&, const BST<oK,oV,oC>&);
};

#include "BST.cpp"

#endif //BST_H__ 
