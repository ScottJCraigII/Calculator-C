#include <cstdlib> 
#include <iostream>
#include <string>
using namespace std;
/***************************************************************************
 * Name: Scott Craig
 * Email: sjcraig@email.sc.edu
 * Function: Calculator object header
 * 
 * Copyright (C) 2019 by Scott Craig                                       *
 *                                                                         *
 ***************************************************************************/
class Calculator{

	public:
		Calculator();
		Calculator(double);	
		~Calculator();
		
		void print() const;
		void clear();
		
		double add(double);
		double subtract(double);
		double multiply(double);
		double divide(double);
		double power(int);
		double power(double, int);
		
	private:
		string expression;
		double result;
		bool cleared;
};
