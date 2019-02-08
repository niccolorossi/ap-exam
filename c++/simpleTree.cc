template<class K>
class BinaryNode
{
	K valore;
	BinaryNode * sinistra;
	BinaryNode * destra;
	int dimensione;

	BinaryNode (const K& valore, BinaryNode * lt, BinaryNode * rt, int dimensione  = 1)
	: valore{valore}, sinistra{lt},destra(rt), dimensione{dimensione} {}

	friend class BinarySearchTree<K>;
};

template<class K>
class BinarySearchTree
{
	public:
		BinarySearchTree();
		BinasrySearchTree( const BinsarySearchTree& rhs );
		const BinarySearchTree& operator=(
			const BinarySearchTree & rhs);

		void insert( const K& x);
		void remove( const K& x);

		typedef BinaryNode<K> Node;

	protected:
		K elementAt( Node* t) const;
		Node *root;
		K& find( const K& xn Node * t) const;
		void makeEmpty( Node* t) const;
		virtual void insert( const K& x, Node* &t) const;
};


//Trova l'elemento x all'interno dell'albero 

template<class K>

K& BinarySearchTree<K> ::find(const K& x) const
{
	return elementAt( find( x, root));
}

template <class K>
void BinarySearchTree<K>::insert(const K& x, Node* & t) const
{
	if(t == nullptr)
		t = new Node{x, nullptr, nullptr};
	else if (x < t -> valore)
		insert(x, t-> sinistra);
	else if (x > t -> valore)
		insert(x, t -> destra);
	else
		throw DuplicateItemException{};
	t -> dimensione++;
}


int main(int argv, char* argc[]) {
	BinarySearchTree t1 = new BinarySearchTree()
}

