#ifndef __FACTORY__
#define __FACTORY__

#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "mult.hpp"
#include "div.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
class Factory{
   
  public:
    Base* parse(char** input, int length){
	Base* left = new Op(atof(input[1]));
	if (length < 4) { return nullptr; }
	for(int i = 2;i<length-1;i++){
		if(input[i][0]=='+'){   
		   left = new Add(left, new Op(atof(input[i+1])));
		}
		else if(input[i][0]=='-'){
		   left = new Sub(left, new Op(atof(input[i+1])));
		}
		else if(input[i][0]=='*' && input[i][1]=='*'){
		   left = new Pow(left, new Op(atof(input[i+1])));
		}
		else if(input[i][0]=='/'){
		   left = new Div(left, new Op(atof(input[i+1])));
		}
		else if(input[i][0]=='*'){
		   left = new Mult(left, new Op(atof(input[i+1])));
		}
		else{
		  std::cout<< "Error!" << std::endl;
		  return nullptr; 
		}

		i = i + 1;
		
		
	}
	return left;
	}
};

#endif
