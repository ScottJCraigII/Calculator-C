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
	string numStr = to_string(num);
	expression = "("+expression + " + " + numStr+")";
	result = num + result;
	cleared = false;
	return result;
}

double Calculator :: subtract(double num){
	string numStr = to_string(num);
	expression = "("+expression + " - " + numStr+")";
	result = result-num;
	cleared = false;
	return result;
}

double Calculator :: multiply(double num) {
	string numStr = to_string(num);
	expression = "("+expression + " * " + numStr+")";
	result = num * result;
	cleared = false;
	return result;
}

double Calculator :: divide(double num) {
	if (num == 0){
		cout << "Cannot divide by zero\n";
	}else{
		string numStr = to_string(num);
		expression = "("+expression + " / " + numStr+")";
		result = result/num;
	}
	cleared = false;
	return result;
}

double Calculator :: power(int exp) {
	string numStr = to_string(exp);
	expression = "("+expression + ")^(" + numStr+"))";
	
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
			string numStr = to_string(num);
			expression = numStr;
			result = num;
			power(exp);
		}else
			cout << "Cannot call power(double,int) when not cleared";
		cleared = false;
		return result;
}

void Calculator ::print() const{
		cout << "Expression evaluated\n"<<expression 
		<< "=\nResult :" << result << endl;
}

void Calculator ::clear(){
		result = 0;
		expression = "0.0";
		cleared = true;
}
Calculator::~Calculator(){
}
