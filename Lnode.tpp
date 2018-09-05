namespace assignment_4 { 

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



}
