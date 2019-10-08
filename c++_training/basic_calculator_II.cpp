#include <stack>
#include <string>
#include <iostream>
#include <variant>
#include "typeinfo.h"

int basic_calculator_II(std::string exp)
{
	std::vector<std::variant<int,char>> reverse_polish;
	std::stack<char> operators;
	int num = 0;
	for(int i = 0; i<exp.length(); ++i){
		if(  exp[i]>='0' && exp[i]<='9' ){
			num = num*10 + exp[i] - '0';
		}
		if(exp[i]<'0' || exp[i]>'9' || i == len-1){
			std::variant<int, char> v = num;
			reverse_polish.push_back(v);
		}
		if((exp[i]<'0'&&exp[i]!=' ') || (exp[i]>'9'&& exp[i]!=' ')){
			if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '('){
				operators.push(exp[i]);
			}else if(exp[i] == ')'){
				while(operators.top() != '('){
					std::variant<int,char> v = operators.top();
					operators.pop();
					reverse_polish.push_back(v);
				}
				operators.pop();
			}
			num = 0;
		}
	}
	while(!operators.empty()){
		std::variant<int, char> v = operators.top();
		reverse_polish.push_back(v);
		operators.pop();
	}
	// process reverse polish

	std::stack<int> res;
	for(int i = 0; i<reverse_polish.size(); ++i){
		if(typeid(reverse_polish[i])==typeid(int)){
			res.push(reverse_polish[i]);
		}else if(typeid(reverse_polish[i])==typeid(char)){
			int a = res.top();
			res.pop();
			int b  = res.top();
			res.pop();
			if(reverse_polish[i] == '+') res.push(a+b);
			if(reverse_polish[i] == '-') res.push(a-b);
			if(reverse_polish[i] == '*') res.push(a*b);
			if(reverse_polish[i] == '/') res.push(a/b);
		}
	}
	return res.top()	;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}