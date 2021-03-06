#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Rand : public Base {
	public:
		Rand() : Base() {value1 = rand() % 100;}
		virtual double evaluate() {return value1;}
		virtual string stringify() {
			number = to_string(value1);
			string out = "";
			for(unsigned i = 0; i <= number.find(".") + 2; ++i){
				out += number.at(i);
			}
			return out;
		}
	private:
	string number;
	double value1;
};

#endif //__RAND_HPP__

