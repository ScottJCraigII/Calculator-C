/***************************************************************************
 * Name: Casey Cole
 * Email: coleca@email.sc.edu
 * Function: Main driver for Account object
 * 
 * Copyright (C) 2019 by Casey Cole                                        *
 *                                                                         *
 ***************************************************************************/
 
#include <cstdlib>
#include <iostream>
#include "Calculator.h"


int main(int argc, char** argv) {
	
	Calculator calc1(10);
	calc1.print(); 
	
	calc1.add(10); 
	calc1.print(); 
	
	calc1.divide(0); 
	calc1.print();
	
	calc1.power(2); 
	calc1.print();

	calc1.subtract(1); 
	calc1.print();
	
	calc1.multiply(10); 
	calc1.print();
	
	calc1.power(5,2);
	calc1.print();
	
	calc1.clear(); 
	calc1.print();
	
	calc1.power(-2,-3);
	calc1.print();

    return 0;
}
