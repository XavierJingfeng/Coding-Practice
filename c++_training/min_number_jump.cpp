#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>

int min_steps_dp(std::vector<int> &input)
{
	//solution dp
	int len = input.size();
	if(len == 0 || len == 1) return 0;
	std::vector<int> dp(len, 0);
	for(int i = len-2; i>=0; --i){
		int min = input.size()+1;
		for(int j = i+1; j<len; ++j){
			if(i+input[i] >= j){
				min = std::min(1+dp[j], min);
			}
		}
		dp[i] = min;
	}
	return dp[0]>len ? -1 : dp[0];

}

int min_steps_greedy(std::vector<int> &input)
{
	int range = 0;
	int last = 0;
	int next_range = input[0];
	int steps = 0;
	int len = input.size();
	if(len == 0 || len == 1) return 0;
	for(int i = 0; i<len; ++i){
		if(i>next_range) return -1;
		if(i == 0) steps++;
		if( i>range){
			steps++;
			range = next_range;
			std::cout<<"i: "<<i<<std::endl; 
		}
		if(i+input[i]>next_range){
			next_range = input[i]+i;

		}
		if(i+input[i]>=len-1) return steps;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	/* code */
	
	std::vector<std::vector<int>> v({
										{2,3,1,1,4},
										{2,2,0,0,4},
										{3,7,1,4,1,8,1,1,1,1,1,1,1},
										{1,1,1,1,1,1},
										{5,2,3,4,1,7,6},
										{2,0,0}
									});
	
	std::cout<<min_steps_greedy(v[3])<<std::endl;
	std::cout<<min_steps_dp(v[3])<<std::endl;
	for(int i = 0; i<v.size(); ++i){
		assert(min_steps_dp(v[i]) == min_steps_greedy(v[i]));
	}

	return 0;
}