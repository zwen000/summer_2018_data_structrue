#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

template <class Item>
    class queue
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS -- See Appendix E if this fails to compile.
        typedef std::size_t size_type;
        typedef Item value_type;
        static const size_type CAPACITY = 30;
        // CONSTRUCTOR
        queue( );
        // MODIFICATION MEMBER FUNCTIONS
        void pop( );
        void push(const Item& entry);
        // CONSTANT MEMBER FUNCTIONS
        bool empty( ) const { return (m_count == 0); }
       	Item front( ) const
		{
        	assert(!empty( ));
			return m_data[m_first];
    	}
    	size_type size( ) const { return m_count; }
        void show() {
        	for(int i = m_first; i < (m_first + m_count);i++ )
        		cout<< m_data[i%CAPACITY]<<"\n"; 
        }	
    private:
        Item m_data[CAPACITY];   // Circular array
        size_type m_first;       // Index of item at front of the queue
        size_type m_last;        // Index of item at rear of the queue
        size_type m_count;       // Total number of items in the queue

        // HELPER MEMBER FUNCTION
        size_type next_index(size_type i) const { return (i+1) % CAPACITY; }
    };
    
    template <class Item>
    queue<Item>::queue( )
    {
        m_count = 0;
        m_first = 0;
        m_last = CAPACITY - 1;
    }
    
   
    template <class Item>
    void queue<Item>::pop( )
    // Library facilities used: cassert
    {
        assert(!empty( ));
        m_first = next_index(m_first);
        --m_count;    
    }
    
    template <class Item>
    void queue<Item>::push(const Item& entry)
    // Library facilities used: cassert
    {
        assert(size( ) < CAPACITY);
        m_last = next_index(m_last);
        m_data[m_last] = entry;
        ++m_count;
    }

    
int main()
{
	queue<int> a;
	a.push(2);
	a.push(1);
	a.push(10);
	a.push(17);
	a.push(31);
	a.push(15);
	a.pop();
	a.show();
	
	return  0;
} 
