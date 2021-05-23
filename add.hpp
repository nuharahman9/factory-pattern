#ifndef __ADD_HPP__
#define __ADD_HPP__


#include "base.hpp"
#include "op.hpp"
#include "Operator.hpp"


class Add: public Operator{
	 
    public:
	Add(Base* left,Base* right ):Operator(left,right){	}
	double evaluate() {return value1->evaluate()+value2->evaluate();}
	std::string stringify() {return value1->stringify()+" + "+value2->stringify();}

};

#endif	

