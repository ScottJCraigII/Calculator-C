#include "Calculator.h"

Calculator::Calculator(){
	result =0;
	expression = "0.0";
	cleared = true;
}
Calculator::Calculator(double num){
	result = num;
	expression = num;
	cleared = true;
}	

double Calculator :: add(double num) {
	expression = "("+expression + ") + " + to_string(num);
	result = num + result;
	cleared = false;
	return result;
}

double Calculator :: subtract(double num){
	expression = "("+expression + ") - " + to_string(num);
	result = result-num;
	cleared = false;
	return result;
}

double Calculator :: multiply(double num) {
	expression = "("+expression + ") * " + to_string(num);
	result = num * result;
	cleared = false;
	return result;
}

double Calculator :: divide(double num) {
	if (num == 0){
		cout << "Cannot divide by zero\n";
	}else{
		expression = "("+expression + ") / " + to_string(num);
		if (result != 0)
			result = result/num;
	}
	cleared = false;
	return result;
}

double Calculator :: power(int exp) {
	expression = "("+expression + ")^(" + to_string(exp)+")";
	
	double base = result;
	int neg = 1;
	if (result < 0)
		neg = -1;
		
	if (exp ==0 )
		result = 1;
	else if( exp>=1 ){
		for(int i = 1;i<exp;i++){
			result = result * base;
		}
	}else if ( exp<=-1 ){
		exp = exp * -1;
		for(int i = 1;i<exp;i++){
			result = result * base;
		}
		result = 1/result;
	}else { cout << "Program will not do square roots";}
	
	if (exp%2 ==1)
		result = result *neg;
	cleared = false;
		
	return result;
}

double Calculator::power(double num, int exp){
		if (cleared){
			expression = to_string(num);
			result = num;
			power(exp);
		}else
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
