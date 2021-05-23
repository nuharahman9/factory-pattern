#include <iostream>

#include "factory.hpp"


int main(int argv, char** argc) {
	Factory* factory = new Factory();
	Base* calc = factory->parse(argc, argv);
	if (calc) {
		std::cout << calc->stringify() << " = " << calc->evaluate() << std::endl;
	}
	else {
		std::cout << "Invalid input!" << std::endl;
	}
	
	delete factory;
	delete calc;
return 0;
}

