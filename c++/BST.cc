#include "BST.h"

template<typename K, typename V, typename C>
bool BST<K,V,C>::insert(Node* curr_node, const K& key, const V& value) {
	//confrontiamo usando il templated operator il valore che vogliamo aggiungere
	//con quello che invece abbiamo nel nodo corrente (l'operatore funziona come
	// > perchè abbiamo messo come default value C = std::greater<K>)
	if(cfr(curr_node->data.first, key)) {
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
			curr_node -> left.reset(new Node(key, value, curr_node));
		} else {
		//anche qua per recuperare il pointer al nodo nuovo a cui ci interes
		//sa arrivare utilizziamo un altro metodo degli unique_ptr che è get
		// che fa proprio questa cosa qua.
			insert(curr_node->_left.get(), key, value);
		} 
	} else if (cfr(key, curr_node -> data.first)) {
		//è più grande, bisogna andare a destra e come prima bisogna stare
		// attenti ai due casi. 
		if(!curr_node -> _right) {
			curr_node -> _right.reset(new Node(key, value, curr_node))
		} else {
			insert(curr_node -> _right.get(), key, value);
		} 
	} else return false; // in caso di duplicati il risultato e false.
	
	return true; // nel caso in cui abbia finito tutto correttamente ritorna true
}

template<typename K, typename V, typename C>
bool BST<K, V, C>::Insert(const K& key, const V& value) {
	// nel chiamare quindi il metodo finale bisogna distinguere due casi fondame
	// ntali : ha già dei nodi, oppure no?
	if(!root) {
	// in questo caso il nostro albero non ha radice quindi il nodo che inseriamo
	// sarà il primo. Utilizziamo come prima il metodo reset degli unqiue ptr.
	// nullptr è il pointer al parent del nodo che per la root è per forza uguale
	// a nullptr
		root.reset(new Node(key, value, nullptr));
		return true;
	} else {
		//qua invece chiamiamo la funzione insert. Anche qui pepr recuperare
		//il pointer al nodo che ci interessa (in questo caso la radice) 
		// usiamo metodo get degli unique_ptr
		return insert(root.get(), key, value);
	}	
}


