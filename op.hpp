#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
	double  operand;
	
    public:
        Op(double value) : Base() {
         	operand = value;
 	}
	
        virtual double evaluate() { return operand; }
        virtual std::string stringify() {
		std::stringstream ss;
		ss.precision(3);
		ss<<operand; 
		return ss.str();
 		}
};

#endif
