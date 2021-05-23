#ifndef __DIV_HPP__
#define __DIV_HPP__

#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include "Operator.hpp"
class Div: public Operator{
	 
    public:
	Div(Base* left,Base* right ):Operator(left,right){	}
	double evaluate() {
		if(value2->evaluate()==0){
		try{
		  throw "Invalid";
		
		}	
		catch(const char* e){
	         std:: cout<< e<<std::endl;
		}
		}
		else{
		return value1->evaluate()/value2->evaluate();
}
}
	std::string stringify() {return value1->stringify()+" / "+value2->stringify();}

};

#endif
