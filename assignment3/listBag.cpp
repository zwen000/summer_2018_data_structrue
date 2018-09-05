#include"listBag.h"
#include <iostream> 
#include <cstdlib> 
namespace assignment3 { 
typedef int value_type;

//constructor 
keyNode::keyNode(value_type key, value_type value)
{
	m_key = key;
	m_linkP = NULL;
	m_linkN = new valueNode(value);
	m_linkN -> set_linkP (this); 
}

valueNode::valueNode(value_type data) 
{
	m_value = data;
	m_linkP = NULL;
	m_linkN = NULL;
}




list::list()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

void list::head_insert(value_type key,value_type val)
{

	if(head == NULL && tail == NULL)
	{
		keyNode* insert  = new keyNode(key,val);
		head = insert;
		tail = head->linkN();
		size++;
		return;
	}
	if(key_exist(key)) return;
	keyNode* insert = new keyNode(key,val);
	head->set_linkP(insert->linkN());
	(insert->linkN() ) ->set_linkN(head);
	head =insert;
	size++;
}

bool list::key_exist(value_type k)
{
	keyNode* cursorK = head;
	valueNode* cursorV= cursorK->linkN();
	while(cursorV->linkN() != NULL )
	{
		if(cursorK->getK() == k)
			return 1;
		cursorK = cursorV ->linkN();
		cursorV= cursorK->linkN();
	}
	if(cursorK->getK() == k) return 1; 
	return 0;
}

value_type list::retrive(value_type k)
{
	keyNode* cursorK = head;
	valueNode* cursorV= cursorK->linkN();
	
	while(cursorV->linkN() != NULL )
	{
		if(cursorK->getK() == k)
		{
			return (cursorK->linkN())->getV();
		}
		cursorK = cursorV ->linkN();
		cursorV= cursorK->linkN();
	}
	if(cursorK->getK() == k)
	{
		return (cursorK->linkN())->getV();
	}
	
	return value_type();
}

void list::remove(value_type key)
{
	if(! key_exist(key)) return; 
	keyNode* cursorK = head;
	valueNode* cursorV= cursorK->linkN();
	//pointers for the key-value pair to remove
	keyNode* removeK = NULL;
	valueNode* removeV =NULL;
	bool found = 0;
	
	while( (cursorV->linkN() != NULL)  && (!found) )
	{
		if(cursorK->getK() == key)
		{
			removeK = cursorK;
			removeV = cursorK->linkN();
			found = 1;
		}		
		cursorK = cursorV ->linkN();
		cursorV= cursorK->linkN();
	}
	// when it reach the last pair of the list
		if(cursorK->getK() == key )
		{
			removeK = cursorK;
			removeV = cursorK->linkN();
			found = 1;
		}
	
	if(found == 0) return;
	if(removeK == head)
	{
		(removeV->linkN() ) -> set_linkP(NULL);
		head = removeV->linkN();
	} 
	else if(removeV == tail )
	{
		
		tail = removeK->linkP(); 
		(removeK->linkP()) -> set_linkN(NULL);
		 
	}
	else
	{
		(removeK->linkP() ) -> set_linkN(removeV->linkN() );
		(removeV->linkN() ) -> set_linkP(removeK->linkP() );
	}
	delete removeK;
	delete removeV;
	size--;
}

//for test
void list::show_from_left()
{
	keyNode* cursorK = head;
	valueNode* cursorV= cursorK->linkN();
	std::cout <<"key: " << cursorK->getK() <<"   value: "<<cursorV->getV() <<"\n";
	while(cursorV->linkN() != NULL )
	{
		cursorK = cursorV->linkN();
		cursorV= cursorK->linkN();
		std::cout <<"key: " << cursorK->getK() <<"   value: "<<cursorV->getV() <<"\n";
	}
	std::cout<<"\n";	
}
//for test
void list::show_from_right()
{
	valueNode* cursorV = tail;
	keyNode* cursorK = cursorV->linkP(); 
	std::cout <<"key: " << cursorK->getK() <<"   value: "<<cursorV->getV() <<"\n";
	while(cursorK->linkP() != NULL )
	{
		cursorV= cursorK->linkP();
		cursorK = cursorV->linkP();
		
		std::cout <<"key: " << cursorK->getK() <<"   value: "<<cursorV->getV() <<"\n";
	}
	std::cout<<"\n";
}

void list::sort()  // O(N^2) 
{
	
	keyNode* cursorK ;
	valueNode* cursorV;
	
	keyNode* currK ;
	valueNode* currV;
	
	value_type tmpK;
	value_type tmpV;
	int count;
	
	
		for(int i =0;i<size;i++)
		{
			cursorK = head;
			valueNode* cursorV= head->linkN();
	
			keyNode* currK = cursorV->linkN();
			valueNode* currV= currK->linkN();
			for(count=0; count<size-2;count++)
			{
			
				if( currK->getK() < cursorK->getK() ) 
				{
					tmpK= currK->getK();
					tmpV = currV->getV();
					currK->set_data(cursorK->getK() );
					currV->set_data(cursorV->getV() );
					cursorK->set_data(tmpK);
					cursorV->set_data(tmpV);
				}
					cursorK = cursorV->linkN();
					cursorV= cursorK->linkN();
					currK = cursorV->linkN();
					currV= currK->linkN();
				
			}
			if( count== size-2 && currK->getK() < cursorK->getK())
			{
				tmpK= currK->getK();
				tmpV = currV->getV();
				currK->set_data(cursorK->getK() );
				currV->set_data(cursorV->getV() );
				cursorK->set_data(tmpK);
				cursorV->set_data(tmpV);
			}
			
		}
			
		

		
		
}


}
