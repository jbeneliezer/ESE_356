#include "systemc.h"
#include "bye.h"

// Hello_world is module name
SC_MODULE (hello_world) { 
	SC_CTOR (hello_world) { 
	// Nothing in constructor   
	SC_THREAD(say_hello);
	}  

	void say_hello() {    
		//Print "Hello World" to the console.    
		cout << "Hello World.\n";  
	int d = 10;
	sc_time t1(d, SC_NS);
	sc_time t2(10, SC_NS);
	if (t1 == t2)
		cout << "checked\n";
	} 
}; 

// sc_main in top level function like in C++ main 
int sc_main(int argc, char* argv[]) {  
	hello_world hello("HELLO");  
	bye_world bye("BYE");  
	// Print the hello world  nd bye world
	hello.say_hello();  
	bye.say_bye();  
	return(0);
}
