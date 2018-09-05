#ifndef ASSIGNMENT_3
#define ASSIGNMENT_3

#include <cstddef> 
#include <iostream> 


namespace assignment3 { 
//prototype
class keyNode;
class valueNode;
class list;


class keyNode
{
	public:
		typedef int value_type;
		
		
		keyNode(value_type key = value_type());
		keyNode(value_type, value_type);
		
		
		void set_data(value_type new_data) { m_key= new_data;}	
		void set_linkP(valueNode* new_link) {m_linkP = new_link;}
	//	void set_linkN(valueNode* new_link) {m_linkN = new_link;}
		const valueNode* linkP() const { return m_linkP; }
		const valueNode* linkN() const { return m_linkN; }
		valueNode* linkP()  { return m_linkP; }
		valueNode* linkN() { return m_linkN; }
		value_type getK() const {return m_key;}
	private:
		value_type m_key;
		valueNode * m_linkP;
		valueNode * m_linkN;
		
	
};


	
class valueNode
{
	public:
		typedef int value_type;
		valueNode(value_type data = value_type());
		void set_data(value_type new_data) { m_value= new_data;}	
		void set_linkP(keyNode* new_link) {m_linkP = new_link;}
		void set_linkN(keyNode* new_link) {m_linkN = new_link;}
		const keyNode* linkP() const { return m_linkP; }
		const keyNode* linkN() const { return m_linkN; }
		keyNode* linkP()  { return m_linkP; }
		keyNode* linkN() { return m_linkN; }
		value_type getV() const {return m_value;}
	private:
		value_type m_value;
		keyNode * m_linkP;
		keyNode * m_linkN;
	
	
};

//key-value-key-value-key-value
class list
{
	public:
		typedef int value_type;
		list();
		void head_insert(value_type,value_type);
		value_type retrive(value_type);
		void remove(value_type);
		void sort(); // O(N^2) 
		void show_from_left(); //for test
		void show_from_right();	//for test
	private:
		keyNode* head;
		valueNode* tail;
		bool key_exist(value_type);
		int size;
};
}
#endif

