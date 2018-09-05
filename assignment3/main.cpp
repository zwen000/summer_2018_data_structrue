#include <iostream>
#include <cstdlib>  
#include"listBag.h"
using namespace std;
using namespace assignment3;


typedef int value_type;

int main()
{
	
	value_type q = 5, w=7;
	list a;
	a.head_insert(0,0);
	a.head_insert(1,1);
	a.head_insert(2,2);
	a.head_insert(3,3);
	a.head_insert(4,8);
//	a.remove(0);
//	a.remove(1);
	cout<<a.retrive(4)<<endl;
	a.show_from_left();
	a.show_from_right();
	
	a.sort();
	a.show_from_left();
	return 0;
}





