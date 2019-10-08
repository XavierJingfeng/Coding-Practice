#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>

int longest_ascending_subsequence_dp(std::vector<int> &input)
{
	// solution with dp
	if(input.size() == 0) return 0;
	int len = input.size();
	std::vector<int> maxlen(len, 1);
	int max = 1;
	for(int i = 1; i<len; ++i){
		for(int  j = 0; j<i; ++j){
			if(input[i]>input[j]) maxlen[i] = std::max(maxlen[i], maxlen[j]+1);
		}
		max = std::max(max, maxlen[i]);
	}
	return max;
}

int longest_ascending_subsequence_greedy(std::vector<int> &input)
{
	// greedy
	if(input.size() == 0) return 0;
	std::vector<int> res;
	for(int i = 0; i<input.size(); i++)
	{
		auto it = std::lower_bound(res.begin(), res.end(), input[i]);
		if(it == res.end())
		{
			res.push_back(input[i]);
		}else
		{
			*it = input[i];
		}
	}
	return res.size();
}

int main(int argc, char const *argv[])
{
	std::vector<int> input({4,10,4,3,8,9});
	
	assert(longest_ascending_subsequence_greedy(input) == longest_ascending_subsequence_dp(input));
	/* code */
	return 0;
}