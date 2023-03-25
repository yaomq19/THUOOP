#include <iostream>
#include "Example.h"

using namespace std;

int Example::Ninstances = 0;	// (2)

Example::Example(int data) {
	m_data = data;
	this->id = ++(this->Ninstances);
	cout<<"Example #"<<this->id<<" is created"<<endl;// (3)
	
}

void Example::getData() {
	cout<<"The data of Example #"<<this->id<<" is "<<m_data<<endl;// (4)
}

Example::~Example() {
	cout<<"Example #"<<this->id<<" is destroyed"<<endl;// (5)
}