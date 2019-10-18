/***************************************************************************
 * Name: Scott Craig
 * Email: sjcraig@email.sc.edu
 * Function: Calculator object 
 * 
 * Copyright (C) 2019 by Scott Craig                                       *
 *                                                                         *
 ***************************************************************************/

#include "Calculator.h"
//default constructor
Calculator::Calculator(){
	result =0;
	expression = "0.0";
	cleared = true;
}
//constructor with base result passed in through argument
Calculator::Calculator(double num){
	result = num;
	expression = to_string(num);
	cleared = false;
}	
//add function
double Calculator :: add(double num) {
	expression = "("+expression + ") + " + to_string(num);
	result = num + result;
	cleared = false;
	return result;
}
//subtract function
double Calculator :: subtract(double num){
	expression = "("+expression + ") - " + to_string(num);
	result = result-num;
	cleared = false;
	return result;
}
//multiply function
double Calculator :: multiply(double num) {
	expression = "("+expression + ") * " + to_string(num);
	result = num * result;
	cleared = false;
	return result;
}
//divide function
double Calculator :: divide(double num) {
	if (num == 0){		// check division by zero
		cout << "Cannot divide by zero\n";
	}else{
		expression = "("+expression + ") / " + to_string(num);
		if (result != 0) //if the numerator is zero set result to zero insteead of infinity
			result = result/num;
	}
	cleared = false;
	return result;
}
//exponent function
double Calculator :: power(int exp) {
	expression = "("+expression + ")^(" + to_string(exp)+")";
	
	double base = result; //variable for repeated multiplication
	
	int neg = 1; //coefficient for keeping track of negative exponents
	if (result < 0)
		neg = -1;	
	if (exp ==0 ) //any num to the power of zero is one
		result = 1;
	else if( exp>=1 ){ //positive exponents
		for(int i = 1;i<exp;i++){
			result = result * base;
		}
	}else if ( exp<=-1 ){ //negative exponents
		exp = exp * -1;
		for(int i = 1;i<exp;i++){
			result = result * base;
		}
		result = 1/result;
	}else { cout << "Program will not do square roots";}//program will not compute roots, requirement documents(obj funtion 6)had the exponent	
														//argument as a  double, which would allow roots which this algorithm won't solve							
	cleared = false;		
	return result;
}

//expontent fuction with two args, base and exponent
double Calculator::power(double num, int exp){
		if (cleared){
			expression = to_string(num);
			result = num;
			power(exp);
		}else       //prevents the power function from overriding running total
			cout << "Error, Cannot call power(double,int) when not cleared\n"; 
		cleared = false;
		return result;
}

void Calculator ::print() const{
		cout << "Expression evaluated:\n"<<expression 
		<< "=\nResult :" << result << endl;
}

void Calculator ::clear(){
		result = 0;
		expression = "0.0";
		cleared = true;
}
Calculator::~Calculator(){
}
