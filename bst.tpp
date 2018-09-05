
namespace assignment_4 { 



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

}
