#ifndef __OPERATOR_HPP__
#define __OPERATOR_HPP__
#include "base.hpp"


class Operator: public Base{
protected:
	Base* value1;
	Base* value2;

public:
	Operator(Base* left,Base* right){
	value1=left;
	value2=right;
}
	virtual double evaluate()=0;
	virtual std::string stringify()=0;	
};

#endif

