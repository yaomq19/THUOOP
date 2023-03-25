#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
	
	cout << "--------create_example is ready--------\n";
	
	Example* e[10];
	
	for (int i = 0; i < n; i++)
		e[i] = new Example(i);
			
	static Example e6(2333);// (6)
	for (int i = 0; i < n; i++)
		e[i]->getData();
    for (int i = 0; i < n; i++)
		delete e[i];
	delete[] e;
    e6.getData();
    
	cout << "--------create_example is over--------\n";
}

Example e1(23);// (7)

int main() {

	cout << "--------main_function is ready--------\n";

	Example e2(233);// (8)
		
	create_example(3);
	
	Example e7(23333);// (9)
    e1.getData();
    e2.getData();
    e7.getData();

	cout << "--------main_function is over---------\n";
	
	Example * e = new Example[10];
	delete[]e;
	return 0;
}
