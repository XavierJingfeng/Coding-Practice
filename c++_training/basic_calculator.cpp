#include <stack>
#include <iostream>
#include <string>

int basic_calculator(std::string exp){
	int num = 0;
	char op = '+';
	int len = exp.length();
	std::stack<int> stack;

	for(int i=0; i<len; i++){
		if(exp[i]>='0' && exp[i]<='9'){
			num = num*10 + exp[i] - '0';

		}
		
		if(    (exp[i]<'0' && exp[i]!=' ') 
			|| (exp[i]>'9' && exp[i]!=' ')
			|| i == len-1){
			if(op == '+') stack.push(num);
			if(op == '-') stack.push(-num);
			if(op == '*' || op == '/'){
				int num2 = stack.top();
				stack.pop();
				if(op == '*') stack.push(num2*num);
				if(op == '/') stack.push(num2/num);
			}
			op = exp[i];
			num = 0;
		}
	}
	int sum = 0;
	while(!stack.empty()){
		sum+=stack.top();
		std::cout<<stack.top()<<std::endl;
		stack.pop();
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	std::string exp = "5-3+6*7+10";
	std::cout<<"res: "<<basic_calculator(exp)<<std::endl;
	return 0;
}