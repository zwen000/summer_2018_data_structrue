#include<iostream>
#include<algorithm>
using namespace std;

class maxHeap
{
	
	public:
		maxHeap(size_t init_size);
		size_t size() {return used;}
		void insert(int);
		void show() {
			for(int i = 0; i < used; i++)
				cout<< arr[i]<<"\n";
		}
		void popMax();
		int getMax() { return arr[0]; }
		int& operator[](size_t);
		bool empty() {return (used==0);		} 
	private:
		int* arr;
		size_t capacity;
		size_t used;
}; 

maxHeap::maxHeap(size_t init_size=15)
{
	capacity = init_size;
	arr = new int[capacity];
	used = 0;

}

void maxHeap::insert(int data)
{
	if(used == capacity)
	{
		capacity *= 2;
		int *new_arr = new int[capacity];
		copy(arr, (arr+used), new_arr );
		delete arr;
		arr = new_arr;
	}
	int i = used;
	arr[used++] = data;
	int tmp;
	while(i != 0 && arr[ (i-1)/2 ] < arr[i] )
	{	
		tmp = arr[i];
		arr[i] = arr[ (i-1)/2 ];
		arr[(i-1)/2] = tmp;
		i = (i-1)/2;
	}
}

void maxHeap::popMax()
{
	if(used==0) return;
	if(used==1)
	{
		used--;
		return;
	}
	arr[0] = arr[used-1];
	--used;
	int i = 0;
	int tmp;
	while((2*i+1)<used && (arr[i] < arr[2*i+1] ||  arr[i] < arr[2*i+2] ) )
	{
		/* 
		if(arr[i] < arr[2*i+1] &&  arr[i] < arr[2*i+2])
		{
			if(arr[2*i+1] > arr[2*i+2])
			{
				tmp = arr[i];
				arr[i] = arr[2*i+1];
				arr[2*i+1] =  tmp;
				i = 2*i+1;
				continue;
			}
			else
			{
				tmp = arr[i];
				arr[i] = arr[2*i+2];
				arr[2*i+2] =  tmp;
				i = 2*i+2;
				continue;
			}	
		}*/ 
		if(arr[2*i+2] < arr[2*i+1])
		{
			tmp = arr[i];
			arr[i] = arr[2*i+1];
			arr[2*i+1] =  tmp;
			i = 2*i+1;
			continue;
		}
		else if(arr[2*i+1] < arr[2*i+2])
		{
			tmp = arr[i];
			arr[i] = arr[2*i+2];
			arr[2*i+2] =  tmp;
			i = 2*i+2;
			continue;
		}	
	}
}

int& maxHeap::operator[](size_t index)
{
	return arr[index];
}

std::ostream& operator<<(ostream& out, maxHeap h)
{
	int l = h.size();
	for(int i = 0; i < l; i++)
		out<< h[i]<<"\n";
	return out;
} 

int main()
{
	maxHeap ab;
	ab.insert(25);
	ab.insert(66);
	ab.insert(34);
	ab.insert(82);
	ab.insert(14);
	ab.insert(75);
	ab.insert(74);
	ab.insert(32);
	ab.insert(8);
	ab.popMax();

	cout <<ab;
	return 0;
} 
