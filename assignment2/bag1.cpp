#include  "bag1.h"
#include<climits>
#include<string>
namespace assignment2_Bag {
	
	bag::bag()
	{
		used = 0;
	}
	
	void bag::show() 
	{
		for(int i = 0; i <used;i++)
			std::cout <<"key"<<i+1<<": "<<key[i]<<"  "<<"val"<<i+1<<": "<<val[i]<<"\n"; 
	}
	
	void bag::shows()
	{
		for(int i = 0; i <used;i++)
		{
			std::cout <<"key"<<i+1<<": "<<key[i]<<"  "<<"stud"<<i+1<<": "<< (*stud[i]).first()<< (*stud[i]).last()<<"\n";
		}
	}
	
	void bag::insert(const int& k, const int& value)
	{
		if( !(used < CAPACITY))  return;
		
		if(used==0) // for the first key and value
		{
			key[used] = k;
			val[used++] = value;
		}
		else
		{
			int find = binarySearch (key, used, k);
			if(find != -1)
			{
				val[find] = value;
			}
			else if(find == -1)
			{
				int i;
				if(k>key[used-1])
				{
					key[used] = k;
					val[used++] = value;
				}
				else if(k < key[0])
				{
					for(i=used-1; i >=0; i--)
					{
						key[i+1]=key[i];
						val[i+1]=val[i];
					}
					key[0] = k;
					val[0] = value;
					used++;
				}
				else
				{
					int breakPt;
					for(i = 0; i <used; i++)
						if(k > key[i])
						{
							breakPt = i;
							break;
						}
					for(i=used-1; i > breakPt; i--)
					{
						key[i+1]=key[i];
						val[i+1]=val[i];
					}
					key[breakPt+1] = k;
					val[breakPt+1] = value;
					used++;
				}
			}
		} 
	}

	//insert student
	void bag::insert(const int& k,student s)
	{
		if( !(used < CAPACITY))  return;
		if(used==0) // for the first key and value
		{
			key[used] = k;
			stud[used++] = & s;
		}
		else
		{
			int find = binarySearch (key, used, k);
			if(find != -1)
			{
				stud[find] = &s;
			}
			else if(find == -1)
			{
				int i;
				if(k>key[used-1])
				{
					key[used] = k;
					stud[used++] = &s;
				}
				else if(k < key[0])
				{
					for(i=used-1; i >=0; i--)
					{
						key[i+1]=key[i];
						stud[i+1]=stud[i];
					}
					key[0] = k;
					stud[0] = &s;
					used++;
				}
				else
				{
					int breakPt;
					for(i = 0; i <used; i++)
						if(k > key[i])
						{
							breakPt = i;
							break;
						}
					for(i=used-1; i > breakPt; i--)
					{
						key[i+1]=key[i];
						stud[i+1]=stud[i];
					}
					key[breakPt+1] = k;
					stud[breakPt+1] = &s;
					used++;
				}
			}
		} 
	} 
	
	 // remove for integer value
	void bag::remove(const int& k)
	{
		int find = binarySearch (key, used, k);
		if(find == -1) return;
		if(find==used-1)
			used--;
		else
		{
			for(int i = find;i < used;i++)
			{
				key[i]=key[i+1];
				val[i]=val[i+1];
			}
			used--;
		}
	
	}	
	 //remove for student value
	void bag::sremove(const int& k)
	{
		int find = binarySearch (key, used, k);
		if(find == -1) return;
		if(find==used-1)
		{
			delete stud[k]; 
			used--;
		} 
		else
		{
			delete stud[k]; 
			for(int i = k;i < used;i++)
			{
				key[i]=key[i+1];
				stud[i]=stud[i+1];
			}
			used--;
		}
	}
	
	int bag::retrive(const int& k)
	{
		int find = binarySearch (key, used, k);
		if(find== -1) return INT_MIN;
		return val[find];
	} 
	
	student bag::sretrive(const int& k)
	{
		int find = binarySearch (key, used, k);
		if(find!=-1)
		{
			student tmp(*(stud[find]));
			return  tmp;
		}
		else if(find == -1)
		{
			student tmp;
			return  tmp;
		}
	}
	
	
	int bag::binarySearch( int* array, int size, int val)
	{
		int first = 0;
		int last = size - 1;
		int mid, position = -1;
		bool found = false;
		while(!found && first <= last)
		{
			mid = (first + last)/2;
			if(array[mid] == val)
			{
				found = true;
				position = mid;
			}
			else if(array[mid] > val)
				last = mid-1;
			else
				first = mid + 1;
		}
		return position;
	}	
		
	student::student(std::string a, std::string b)
	{
		first_name=a;
		last_name=b;
	}
	

}
