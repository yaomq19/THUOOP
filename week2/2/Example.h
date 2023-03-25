#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
private:
	static int Ninstances;// (1)
	int id;
	int m_data;
public:
	
	Example(int data);
	void getData();
	~Example();

};
		
#endif