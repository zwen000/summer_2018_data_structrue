#ifndef ASSIGNMENT_BAG_h
#define ASSIGNMENT_BAG_h


#include<iostream>



namespace assignment2_Bag { 

	class student{
		public: 
			student(std::string first = "Jane", std::string last= "Doe");
			std::string first() const {return first_name; } 
			std::string last() const {return  last_name; }
		private:
			std::string first_name;
			std::string last_name; 
	};
	


	class bag{
	
		public:
			static const size_t CAPACITY = 20;
			bag();
			void insert(const int& , const int&);//insert  integer
			void insert(const int&, student s); //insert student
			void remove(const int&); //remove int
			void sremove(const int&); //remove student
			int retrive(const int&); //retrive int
			student sretrive(const int&); //retrive student
			void show();//for test int
			void shows();//for test student
		private:
			int key[CAPACITY];
			int val[CAPACITY];
			int used;
			int binarySearch(int* , int, int);
			student *stud[CAPACITY];
	};
} 



#endif
