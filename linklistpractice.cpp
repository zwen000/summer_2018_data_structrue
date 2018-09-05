#include<iostream> 
#include<cassert>
#include<algorithm> 
#include<cstdlib> 
using namespace std;

class node
{
	public:
		typedef int value_type;
		node(const value_type& init_data = value_type(), node* init_link = NULL)
		{
			m_data= init_data;
			m_link = init_link; 
		}
		
	
		
		value_type data() const {return m_data;}
		
		void set_data(const value_type& new_data) { m_data= new_data;}
		void set_link(node* new_link) {m_link = new_link;}
		
		//this is specify for the const objects
		const node* link() const { return m_link; }//if I call this function "node->link" from a const object, const object can only use const function
		//this is for non-const objects
		node*& link() {return m_link;} //CONST object can't not use non-const function
		//when non-const object calls the funcion, system will look for non-const function first, if couldn't find, then it uses the const function
		
		
		
	private:
		value_type m_data;
		node * m_link;
} ;

	size_t list_length(const node* head_ptr)
	{
		const node *cursor;
		size_t count = 0;
		for(cursor = head_ptr;  cursor != NULL; cursor = cursor ->link())
			count++;
		return count;
	}
/* 
	void list_head_insert(node*& head_ptr, const node::value_type& entry)
	{
		node * insert_ptr;
	//	insert_ptr= new node;
	//	insert_ptr ->set_data(entry);
	//	insert_ptr-> set_link(head_ptr);
		insert_ptr = new node(entry, head_ptr);
		head_ptr =insert_ptr; 
	} */ 
	
	void list_head_insert(node*& head_ptr, const node::value_type& entry)
	{
		head_ptr = new node(entry, head_ptr);
	}
	
	void list_insert_at (node*& head_ptr, size_t index, int entry)
	{
		assert(index <= list_length(head_ptr) );
		if(index==0)
		{
			list_head_insert(head_ptr, entry);
			return;
		}
		node* current = head_ptr; 
		//node* inserted = new node(entry);
		size_t count = 0;
		for(int i = 1; i < index; i++ )
		{
			current = current -> link(); 
		}
		current->set_link(new node(entry, current->link() ) );
	} 
	
	/* professor 
	void list_remove_from(node*& head_ptr, size_t index)
	{
		assert(index < list_length(head_ptr) );
		if(index == 0) 
		{
			node* new_head = head_ptr->link();
			delete head_ptr;
			head_ptr = new_head;
			
		}
		else
		{
			node* current = head_ptr;
			for (int i=1; i < index; i++)
			{
				current = current -> link(); 
			} 
			node* cursor = current -> link();
			current -> set_link( current -> link() -> link()  );
			delete cursor;
		
		}
	}
*/


	void list_remove_from(node*& head_ptr, size_t index)
	{
		assert(index < list_length(head_ptr) );
		if(index == 0) 
		{
			node *remove_ptr= head_ptr;
			head_ptr = head_ptr->link();
			delete remove_ptr;
			return;
		}
		
		else if(index > 0)
		{
			node *current_ptr = head_ptr;
			for (int i=1; i < index; i++)
				current_ptr= current_ptr->link();
			node* remove_ptr = current_ptr->link();
			current_ptr->set_link(remove_ptr->link())  ;
			delete remove_ptr;
		}
	}	

	
	//prof
	void clear_list( node* head_ptr)
	{
		if(head_ptr== NULL) return;
		clear_list(head_ptr->link() );
		delete head_ptr; 
	} 
	
	
	void list_head_remove(node*& head_ptr)
	{
 		node *remove_ptr;
		remove_ptr = head_ptr;
		head_ptr = head_ptr->link( ); 
		delete remove_ptr;
	}

 
	void list_clear(node*& head_ptr)
	{
		while (head_ptr != NULL) 
			list_head_remove(head_ptr);
	}
 
	
	
	
	
	
	
	
	
	void show_list(node*& head_ptr)
	{
		const node *cursor= head_ptr;
		int count = list_length(head_ptr);
		for(cursor = head_ptr;  cursor != NULL && count > 0; cursor = cursor ->link())
		{
			cout <<cursor ->data()<<endl; 
			--count;
		}
		cout<<endl;
	}
	
	/*
	 void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr) 
  	  // Library facilities used: cstdlib
    {
		head_ptr = NULL;
		tail_ptr = NULL;
	
		// Handle the case of the empty list.
		if (source_ptr == NULL)
		    return;
	    
		// Make the head node for the newly created list, and put data in it.
		list_head_insert(head_ptr, source_ptr->data( ));
		tail_ptr = head_ptr;
	    
		// Copy the rest of the nodes one at a time, adding at the tail of new list.
		source_ptr = source_ptr->link( ); 
		while (source_ptr != NULL)
		{
		    list_insert(tail_ptr, source_ptr->data( ));
		    tail_ptr = tail_ptr->link( );
		    source_ptr = source_ptr->link( );
		}
    }*/
    
    node* list_search(node* head_ptr, const node::value_type& target) 
    // Library facilities used: cstdlib
    {
		node *cursor;
	   
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
		    if (target == cursor->data( ))
			return cursor;
		return NULL;
    }


	void insert(node*& head,int num)
	{
		if(head==NULL) 
		{
			head = new node(num, head);
			return;
		}
		else
		{
			insert( head->link(), num );
		}
		
	}
	
	void show(node* head)
	{
		node* cursor = head;
		while(cursor != NULL)
		{
			cout <<cursor->data() <<endl;
			cursor= cursor->link();
		}
	}
	
	
	
	
int main()
{
	node * head=NULL;



//	list_head_insert(head_ptr, 4);
//	list_head_insert(head_ptr, 3);
//	list_head_insert(head_ptr, 2);
//	list_head_insert(head_ptr, 1);
//	insert(head, 5) ;
	insert(head, 6) ;
	insert(head, 7) ;
	insert(head, 8) ;
//	list_remove_from(head_ptr,1);
	show(head);
//	clear_list(head_ptr);
//	list_head_insert(head_ptr, 0);	
//	show_list(head_ptr);
//	list_insert_at(head_ptr,1,10);
//	show_list(head_ptr);
//	cout<<max(1,2);
	return 0; 
} 
/*
node::node(node *pt)
{
	link = pt;
	 
} 
 */
