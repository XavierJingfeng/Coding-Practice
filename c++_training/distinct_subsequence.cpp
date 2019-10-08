#include <iostream>
#include <vector>
#include <string>

int distinct_subsequence(std::string S, std::string T)
{
	int m = S.size();
	int n = T.size();
	int dp[m+1][n+1];
	for(int i = 0; i<=m; ++i)
	{
		for(int j = 0; j<=n; ++j)
		{
			if(j>i){
				dp[i][j] = 0;
			}
			if(i == 0)
			{
				dp[i][j] = 1;
			}else
			{
				if(S[i] == T[j])
				{
					dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
				}else
				{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}
	return dp[m][n];
}

int main(int argc, char const *argv[])
{
	/* code */
	std::string S = "topology";
	std::string T = "to";
	std::cout<<"num:"<<distinct_subsequence(S,T)<<std::endl;
	return 0;
}