namespace assignment_4 { 

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


}
