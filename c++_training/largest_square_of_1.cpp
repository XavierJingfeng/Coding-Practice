#include <iostream>
#include <algorithm>


int largest_square(std::vector<std::vector<int>> M)
{
	int m = M.size();
	if(m == 0) return 0;
	int n = M[0].size();
	int dp[m][n];
	int max = 0;
	for(int i = 0; i<m; ++i){
		dp[i][0] = M[i][0];
	}
	for(int j = 0; j<n; ++j){
		dp[0][j] = M[0][j];
	}
	for(int i = 1; i<m; ++i){
		for(int j = 1; j<n; ++j){
			if(M[i][j] == 0)
			{
				dp[i][j] = 0;
			}else
			{
				int tmp = std::min(dp[i-1][j], dp[i-1][j-1]);
				dp[i][j]= std::min(tmp, dp[i][j-1]) + 1; 
			}
			max = std::max(dp[i][j], max);
		}
	}
	return max;
};

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<std::vector<int>> v({
		{0,1,0,0,1},
		{0,1,1,1,1},
		{0,1,1,1,0},
		{0,0,1,1,1},
		{0,1,0,1,1}
	});
	std::cout<<largest_square(v)<<std::endl;
	return 0;
}