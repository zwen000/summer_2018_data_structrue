#include<iostream>
#include<string>
#include "bag1.h"

using namespace assignment2_Bag;
using namespace std;

int main()
{
	int v1= 100,v2=212, v3=50,v4=1000;
	bag a;
	student aa("A","a");
	student bb("B","b");
	student cc("C","c");
	student dd("D" ,"");
	a.insert(1,aa);
	a.insert(2,bb);
	a.insert(3,cc);
	a.insert(0,dd);
	cout <<"student test: \n";
	a.shows();
	
	student ee = a.sretrive(2); 
	student ff = a.sretrive(10);
	a.insert(4,ee);
	cout<<endl;
	a.shows();
	cout<<endl;	
	
	a.sremove(1);
	a.insert(5,ff);
	a.shows();
	cout<<"\ninteger test: \n";
	bag b;
	b.insert(1,v1);
	b.insert(3,v1);
	b.insert(2,v2);
	b.insert(4,v4);
	b.show();
	cout<<endl;
	b.remove(4);
	b.show();
	cout<<endl;
	cout <<b.retrive(10);

	return 0; 
}

 
