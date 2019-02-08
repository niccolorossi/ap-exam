#include <iostream>
#include <memory>
#include <utility>

#include "BST.h"

template<typename K, typename V, typename C>
bool BST<K,V,C>::insertPrivate(Node* curr_node, const std::pair<K,V>& pair) {
	//confrontiamo usando il templated operator il valore che vogliamo aggiungere
	//con quello che invece abbiamo nel nodo corrente (l'operatore funziona come
	// > perchè abbiamo messo come default value C = std::greater<K>)
	if(cfr(curr_node->_pair.first, pair.first)) {
		//Il valore che vogliamo inserire è più piccolo. Dobbiamo scendere
		// a sinistra. Ci sono due possibilità :
		//1) non ha figli a sinistra e quindi avremo un nuovo nodo
		//2) ha figlio a sinistra e allora occorre chiamare la funzione
		// in maniera ricorsiva
		if(!curr_node -> _left) {
			// per creare un nuovo nodo utilizziamo un metodo degli uniqu
			//pointers che è reset. Essenzialmente quello che fa è cancel
			//lare quello a cui puntava prima left (in questo caso nullp)
			//e ci assegna un nuovo valore in questo caso il pointer al
			//nuovo nodo
			curr_node -> _left.reset(new Node(pair, curr_node));
		} else {
		//anche qua per recuperare il pointer al nodo nuovo a cui ci interes
		//sa arrivare utilizziamo un altro metodo degli unique_ptr che è get
		// che fa proprio questa cosa qua.
<<<<<<< HEAD
			insert(curr_node->_left.get(), key, value);
		}
	} else if (cfr(key, curr_node -> data.first)) {
		//è più grande, bisogna andare a destra e come prima bisogna stare
		// attenti ai due casi.
		if(!curr_node -> _right) {
			curr_node -> _right.reset(new Node(key, value, curr_node));
		} else {
			insert(curr_node -> _right.get(), key, value);
=======
			insertPrivate(curr_node->_left.get(), pair);
		}
	} else if (cfr(pair.first, curr_node -> _pair.first)) {
		//è più grande, bisogna andare a destra e come prima bisogna stare
		// attenti ai due casi.
		if(!curr_node -> _right) {
			curr_node -> _right.reset(new Node(pair, curr_node));
		} else {
			insertPrivate(curr_node -> _right.get(), pair);
>>>>>>> esame/master
		}
	} else return false; // in caso di duplicati il risultato e false.

	return true; // nel caso in cui abbia finito tutto correttamente ritorna true
}

template<typename K, typename V, typename C>
bool BST<K, V, C>::Insert(const std::pair<K,V>& pair) {
	// nel chiamare quindi il metodo finale bisogna distinguere due casi fondame
	// ntali : ha già dei nodi, oppure no?
	if(!root) {
	// in questo caso il nostro albero non ha radice quindi il nodo che inseriamo
	// sarà il primo. Utilizziamo come prima il metodo reset degli unqiue ptr.
	// nullptr è il pointer al parent del nodo che per la root è per forza uguale
	// a nullptr
		root.reset(new Node(pair, nullptr));
		return true;
	} else {
		//qua invece chiamiamo la funzione insert. Anche qui pepr recuperare
		//il pointer al nodo che ci interessa (in questo caso la radice)
		// usiamo metodo get degli unique_ptr
<<<<<<< HEAD
		return insert(root.get(), key, value);
=======
		return insertPrivate(root.get(), pair);
>>>>>>> esame/master
	}
}

template <class K, class V, typename C>
class BST<K,V, C>::Iterator : public std::iterator<std::forward_iterator_tag, V>
{
using Node = BST<K,V,C>::Node;
  Node* current;

public:
  Iterator() {current = nullptr;}
  Iterator(Node* n) : current{n} {}
  Iterator(const Iterator&) = default;                    // copy ctor deleted
  V& operator*() const { return current->_pair.second; }   // dereference operator

  Iterator& operator++()                                  // increment operator
  {
    if (current->_right)
    {
      current = current->_right.get();
      while (current->_left)
      {
        current = current->_left.get();
      }
    }
    else
    {
      Node* aux{current->_parent};
			while(aux && (current == aux->_right.get()))
			{
				current = aux;
				aux = aux->_parent;
			}
			current = aux;
    }
    return *this;
  }

  bool operator==(const Iterator& other) { return current == other.current; }
  bool operator!=(const Iterator& other) { return !(*this == other); }

};


template<typename K, typename V, typename C>
class BST<K,V,C>::Iterator BST<K,V,C>::begin() const
{

	if (root == nullptr){

		return Iterator{root};

	}

	Node* first_node = root.get();

	while (first_node->left != nullptr)
	{

		first_node = first_node->left.get();


	}

	return Iterator{first_node};


}

template<typename K, typename V, typename C>
class BST<K,V,C>::ConstIterator BST<K,V,C>::cbegin() const
{

	if (root == nullptr){

		return ConstIterator{root};

	}

	Node* first_node = root.get();

	while (first_node->left != nullptr)
	{

		first_node = first_node->left.get();


	}

	return ConstIterator{first_node};

}



template <class K, class V, typename C>
class BST<K,V,C>::ConstIterator : public BST<K,V,C>::Iterator
{
 public:

  using parent = BST<K,V,C>::Iterator;
  using parent::Iterator;
  const V& operator*() const { return parent::operator*(); }

};
