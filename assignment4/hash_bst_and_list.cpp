#include<iostream> 
#include<cstdlib> 

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class type>
	class bt_node
	{
		public:
		// TYPEDEF
		typedef type value_type;
		
		// CONSTRUCTOR
		bt_node(
			int k,
		    const type& init_data = type( ),
		    bt_node* init_left = NULL,
		    bt_node* init_right = NULL
		)
		{ 
			m_key = k;
			data_field = init_data; 
		    left_field = init_left; 
		    right_field = init_right;
		}
			
		// MODIFICATION MEMBER FUNCTIONS
		type& data( ) { return data_field; }
		bt_node*& left( ) { return left_field; }
		bt_node*& right( ) { return right_field; }
		int key() {return m_key;	}
		
		void set_key(int new_key) {	m_key= new_key;	}
		void set_data(const type& new_data) { data_field = new_data; }
		void set_left(bt_node* new_left) { left_field = new_left; }
		void set_right(bt_node* new_right) { right_field = new_right; }
			
		// CONST MEMBER FUNCTIONS
		const int key() const{return m_key;	}
		const type& data( ) const { return data_field; }
		const bt_node*& left( ) const { return left_field; }
		const bt_node*& right( ) const { return right_field; }
		bool is_leaf( ) const 
			{ return (left_field == NULL) && (right_field == NULL); }
			    
		private:
			int m_key;
		type data_field;
		bt_node *left_field;
		bt_node *right_field;
	};
	
	template <class type>
	void bst_insert(int, bt_node<type>*& , type);
	template <class type>
	void inorder(bt_node<type>*&);
	template <class type>
	void bst_clear(bt_node<type>*& );
	
//remove	
template <class type>
void bst_remove(bt_node<type>*& , int );
template <class type>
void removeRoot(bt_node<type>*&, int );
template <class type>
int findMinK(bt_node<type>* root ); 
template <class type>
type findMinVal(bt_node<type>* root );
template <class type>
type removeNode(bt_node<type>* , bt_node<type>*, bool);	

template <class type>
type bst_retrieve(bt_node<type>* , int );

template <class type>
bool in_tree(bt_node<type>* , int);




	//insert
	template <class type>
	void bst_insert(int k, bt_node<type>*& root, type value)
	{
		if(root == NULL) 
		{
			root = new bt_node<type>(k,value) ;
			return;
		}
			
		if(root->key() > k)
		{
			if(root->left() == NULL)
				root->set_left(new bt_node<type>(k,value) );
			else
				bst_insert(k,root->left(),value);
		} 
		else
		{
			if(root->right() == NULL) 
				root->set_right(new bt_node<type>(k,value) );
			 else
			 	bst_insert(k, root->right(), value );
		} 
	}

	//inorder print
	template <class type>
	void inorder(bt_node<type>*&  root)
	{
		if(root != NULL) 
		{
			inorder(root->left());
			std::cout << root->key() << " "<< root->data() <<std::endl;
			inorder(root->right());
		} 
	}
	
	
template <class type>
void bst_clear(bt_node<type>*& root )
{
	if(root != NULL)
	{
		bst_clear(root->left() );
		bst_clear(root->right() );
		delete root;
		root = NULL;	
	}
}


template <class type>
void bst_remove(bt_node<type>*& root, int k )
{
	if(root == NULL) return;	
	if(k== root->key())
	{
		removeRoot(root,k);
		
	}
	else if(k < root->key() && root->left() != NULL)
	{
		if((root->left()) ->key()  == k) 
		{
			removeNode(root,root->left(),true);
		}
		else
			bst_remove(root->left(), k);
	} 
	else if(k > root->key() && root->right() != NULL)
	{
		if( (root->right())->key()  == k) 
		{
			removeNode(root, root->right(),false);
		}
		else
			bst_remove(root->right(), k);
	} 
}

template <class type>
void removeRoot(bt_node<type>*& root, int k )
{
	bt_node<type>* delPtr = root;

	int smallestInRightSub;
	if(root->left() == NULL && root->right() == NULL)
	{
		root = NULL;
		delete delPtr;
	}
	 else if(root->left() == NULL && root->right() != NULL)
	{
		root = root->right();
		delPtr->right() = NULL;
		delete delPtr;
	}
	else if(root->left() != NULL && root->right() == NULL)
	{
		root = root->left();
		delPtr->right() = NULL;
		delete delPtr;
	}
	else
	{
		smallestInRightSub = findMinK(root->right());
		bst_remove(root,smallestInRightSub);
		root->set_key(smallestInRightSub) ;
		root->set_data(findMinVal(root->right()));
	} 
}

template <class type>
int findMinK(bt_node<type>* root )
{
	while(root->left() != NULL)
	{
		root = root->left();
	}
	return root->key();
}

template <class type>
type findMinVal(bt_node<type>* root )
{
	while(root->left() != NULL)
	{
		root = root->left();
	}
	return root->data();
}

template <class type>
type removeNode(bt_node<type>* parent, bt_node<type>* match, bool left  )
{
	if(parent != NULL)
	{
		bt_node<type>* delPtr;
		int matchKey = match->key();
		int smallestInRightSub;
		if(match->left() == NULL && match->right() == NULL)
		{
			delPtr = match;
			if(left == true)
				parent->left() = NULL;
			else
				parent->right() = NULL;
			delete delPtr;
		}
		else if(match->left() == NULL && match->right() != NULL)
		{
			delPtr = match;
			if(left == true)
				parent->left() = match->right();
			else
				parent->right() = match->right();
			match->set_right(NULL);
			delete delPtr;
		}
		else  if(match->left() != NULL && match->right() == NULL)
		{
			delPtr = match;
			if(left == true)
				parent->left() = match->left();
			else
				parent->right() = match->left();
			match->set_left(NULL);
			delete delPtr;
		}
		else
		{
			smallestInRightSub = findMinK(match->right());
			bst_remove(match,smallestInRightSub);
			match->set_key(smallestInRightSub);
			match->set_data(findMinVal(match->right()) );
		}
	} 
}

template <class type>
type bst_retrieve(bt_node<type>* root , int k)
{
	bt_node<type>* cursor =  root; 
	while(cursor != NULL)
	{
		if(cursor->key() == k)
			return cursor->data();
		else if( cursor->key() > k) 
			cursor = cursor->left();
		else if( cursor->key() < k) 
			cursor = cursor->right();	
	}
	return type();
}

template <class type>
bool in_tree(bt_node<type>* root , int k)
{
	bt_node<type>* cursor =  root; 
	while(cursor != NULL)
	{
		if(cursor->key() == k)
			return true;
		else if( cursor->key() > k) 
			cursor = cursor->left();
		else if( cursor->key() < k) 
			cursor = cursor->right();	
	}
	return false;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



template <class type>
	class Lnode 
	{
		public:
			Lnode( int k ,const type& init_data = type(), Lnode* init_link = NULL)
			{
				m_key = k;
				m_data= init_data;
				m_link = init_link; 
			}
			type data() const {return m_data;}
			int key() {return m_key; } 
			
			void set_data(const type& new_data) { m_data= new_data;}
			void set_link(Lnode* new_link) {m_link = new_link;}
			const Lnode* link() const { return m_link; }
			Lnode* link() {return m_link;} 			
		private:
			type m_data;
			Lnode * m_link;
			int m_key;
	};
	
	template <class type>
	void list_insert(int , Lnode<type>*&, type); 



	template <class type>
	void list_remove(Lnode<type>*& , int); 
	
	template <class type>
	int	list_length(Lnode<type>*);
	
	template <class type>
	void printlist(Lnode<type>* );
	
	template <class type>
	type list_retrieve(Lnode<type>* , int); 
	
	template <class type>
	void list_clear(Lnode<type>* );
	
	template <class type>
	bool in_list(Lnode<type>* head, int k );
	
template <class type>
void list_insert(int key,Lnode<type>*& head,type entry)
{
	if(head==NULL) 
	{
		head = new Lnode<type>(key,entry);
		return;
	}
	else
	{
		//list_insert( head->link(), entry);
		Lnode<type>* cursor = head;
		while(cursor->link() != NULL)
		{
			cursor = cursor->link();
		}
		cursor->set_link( new Lnode<type>(key,entry) );
	}
}

template <class type>
void list_remove(Lnode<type>*& head,int k)
{
	if(head == NULL) return;

	Lnode<type>* remove;
	if(head->key() == k)
	{
		remove = head;
		head = head->link();
		delete remove;
		return;
	}
	Lnode<type>* cursor = head;	
	while(cursor != NULL)
	{
		if( (cursor->link()) ->key() == k)
		{
			remove = cursor->link();
			break;
		}
		cursor = cursor->link();
	}
	cursor->set_link(remove->link());
	delete remove;
	
}

template <class type>
int	list_length(Lnode<type>* head)
{
	const Lnode<type> *cursor;
	size_t count = 0;
	for(cursor = head;  cursor != NULL; cursor = cursor ->link())
		count++;
	return count;
}

	template <class type>
	void printlist(Lnode<type>* head)
	{
		Lnode<type>* cursor = head;
		while(cursor != NULL)
		{
			std::cout<<cursor->key()<< " " << cursor->data()<<"\n";
			cursor = cursor->link();
		}
			
	}
	
template <class type>
type list_retrieve(Lnode<type>* head, int k )
{
	Lnode<type>* cursor =  head; 
	while(cursor != NULL)
	{
		if(cursor->key() == k)
			return cursor->data();
		else 
			cursor = cursor->link();
			
	}
	return type();
}

template <class type>
void list_clear(Lnode<type>* head)
{
	if(head== NULL) return;
	list_clear(head->link() );
	delete head; 
}


template <class type>
bool in_list(Lnode<type>* head, int k )
{
	
	Lnode<type>* cursor =  head; 
	while(cursor != NULL)
	{
		if(cursor->key() == k)
			return true;
		else 
			cursor = cursor->link();	
	}
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class type>
class bucket; 

template<class type>
class hashtable
{
	public:
		hashtable(int init_size = 50);
		void insert(int , type);
		void remove(int k);
		type retrieve(int k);
	private:
		int tableSize;
		bucket<type>* table;
		int used;
		//hash function
		int hashf(int key) {return key%tableSize; }
		void rehash();
		
};
template<class type>
void treeToList( bt_node<type>* , Lnode<type>*& );


template<class type>
hashtable<type>::hashtable(int init_size) 
{ 
	tableSize = init_size;
	used = 0;
	table = new bucket<type> [tableSize];
/*	for(int i = 0; i<tableSize; i++)
	{
		table[i] = new bucket<type>; 
	}*/
}

template<class type>
void hashtable<type>::insert(int k, type value)
{
	int hashKey = hashf(k);
	used++;
	(table[hashKey].size)++;
	
	if(table[hashKey].size < 12  && table[hashKey].bst == NULL)
	{
		list_insert(k, table[hashKey].list, value);
	}
	else if(table[hashKey].size < 12  && table[hashKey].bst != NULL)
	{
		bst_insert(k, table[hashKey].bst, value);
	}
	else if(table[hashKey].size == 12)
	{
		//convert
		Lnode<type>* cursor = table[hashKey].list;
		while(cursor != NULL)
		{
			bst_insert(cursor->key(), table[hashKey].bst, cursor->data());
		}
		list_clear(table[hashKey].list);
		table[hashKey].list = NULL;
		bst_insert(k, table[hashKey].bst, value);
	}
	else if(table[hashKey].size > 12 )
	{
		bst_insert(k, table[hashKey].bst, value);
	}
	
	if(used > (tableSize * 0.8))
	{
		//rehash
		rehash();
	}
}

template<class type>
void hashtable<type>::remove(int k)
{
	int hashKey = hashf(k);
	if( (table[hashKey].size -1) < 7)
	{
		if(in_list(table[hashKey].list, k) )
		{
			list_remove(table[hashKey].list, k);
			(table[hashKey].size)--;
			used--;
		}
	}
	else if( (table[hashKey].size -1) == 7 && table[hashKey].bst != NULL )
	{
		if(in_tree(table[hashKey ].bst, k) )
		{
			bst_remove(table[hashKey ].bst, k);
			(table[hashKey].size)--;
			used--;
			treeToList( table[hashKey].bst, table[hashKey].list );
			bst_clear(table[hashKey].bst);
		}
	}
	else if( (table[hashKey].size -1) > 7 && table[hashKey ].bst != NULL )
	{
		if(in_tree(table[hashKey ].bst, k) )
		{
			bst_remove(table[hashKey ].bst, k);
			(table[hashKey].size)--;
			used--;
		}
	}
	else if( (table[hashKey].size -1) > 7 && table[hashKey ].list != NULL )
	{
		if(in_list(table[hashKey].list, k) )
		{
			list_remove(table[hashKey].list, k);
			(table[hashKey].size)--;
			used--;
		}
	}
	
}

//non-member helper
template<class type>
void treeToList( bt_node<type>* root, Lnode<type>*& head )
{
	if(root != NULL)
	{
		list_insert(root->key(), head, root->data() );
		if(root->left() != NULL)
			treeToList(  root->left() ,  head );
		if(root->right() != NULL)	
			treeToList(  root->right() ,  head );
	}
}

template<class type>
type hashtable<type>::retrieve(int k)
{
	int hashKey = hashf(k);
	if(table[hashKey].bst != NULL && table[hashKey].list == NULL)
		return bst_retrieve(table[hashKey].bst,k );
	else if(table[hashKey].bst == NULL && table[hashKey].list != NULL)
		return list_retrieve(table[hashKey].list,k );
	else 
		return type();
}

template<class type>
void hashtable<type>::rehash()
{
	hashtable<type> newHash(this->tableSize * 1.5 );
	for(int i = 0 ; i< this->tableSize; i++)
	{
		if(table[i].bst == NULL && table[i].list == NULL)
			continue;
		else if(table[i].bst != NULL) 
		{
			treeToList(table[i].bst, table[i].list);
			bst_clear(table[i].bst);
			Lnode<type>* cursor = table[i].list;
			while(cursor != NULL)
			{
				newHash.insert(cursor->key(), cursor->data() );
				cursor = cursor->link();
			}
			list_clear(table[i].list);
			table[i].list = NULL;
		}
		else if( table[i].list != NULL)
		{
			Lnode<type>* cursor = table[i].list;
			while(cursor != NULL)
			{
				newHash.insert(cursor->key(), cursor->data() );
				cursor = cursor->link();
			}
			list_clear(table[i].list);
			table[i].list = NULL;
		}
	}
	this->table = newHash.table;
	this->tableSize = newHash.tableSize;
	this->used = newHash.used;
}


template<class type>
class bucket
{
	public:
		bucket() {list = NULL;
					bst = NULL;
					size = 0;	}
		Lnode<type>* list;
		bt_node<type>* bst;
		int size;
		
};

int main()
{
	hashtable<char> a; 
	char value;
	int choice;
	int key;

	do{
		cout<< "----------------------------------------------------------\n";
		cout<<"1) Insert\n"<<"2) Remove\n"<<"3) Retrieve\n"<<"4) Quit\n"
			<<"your choice?\n\n";
		cin >>choice;
			
		if(choice == 1)
		{
			cout<< "\nkey ?\n";
			cin >> key;
			cout<< "\nvalue ?\n";
			cin>>value;
			a.insert(key,value);
		}
		else if(choice == 2)
		{
			cout<< "\nkey ?\n";
			cin >> key;
			a.remove(key);
		}
		else if(choice == 3)
		{
			cout<< "\nkey ?\n";
			cin >> key;
			cout<< "key: "<< key<<"\nvalue: "<< a.retrieve(key)<<"\n";
		} 	
	}while(choice != 4);
	return 0;
} 
