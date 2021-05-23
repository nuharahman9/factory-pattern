#ifndef __POW_HPP__
#define __POW_HPP__


#include "base.hpp"
#include "op.hpp"
#include "Operator.hpp"
#include <math.h>
class Pow: public Operator{
	 
    public:
	Pow(Base* left,Base* right ):Operator(left,right){	}
	double evaluate() {return pow(value1->evaluate(),value2->evaluate());}
	std::string stringify() {return value1->stringify()+" ** "+value2->stringify();}

};

#endif

