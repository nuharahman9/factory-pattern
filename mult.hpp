#ifndef __MULT_HPP__
#define __MULT_HPP__


#include "base.hpp"
#include "Operator.hpp"
class Mult: public Operator{
	 
    public:
	Mult(Base* left,Base* right ):Operator(left,right){	}
	double evaluate() {return value1->evaluate()*value2->evaluate();}
	std::string stringify() {return value1->stringify()+" * "+value2->stringify();}

};

#endif

