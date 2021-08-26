#include "systemc.h"

// Bye_world is module name
SC_MODULE (bye_world) { 
	SC_CTOR (bye_world) { 
	// Nothing in constructor   
	}  

	void say_bye();
};
