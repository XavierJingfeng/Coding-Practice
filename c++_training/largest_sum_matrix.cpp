#include <vector>
#include <algorithm>
#include <iostream>

int prefixSum(int i, int j, std::vector<int> v){
	std::vector<int> M(v.size(), 0);
	for(int i = 0; i<v.size(); ++i){
		if(i == 0) M[i] = v[i];
		else M[i] = M[i-1] + v[i];
	}
	return M[j]-M[i]+v[i];
}

int largestSumOfSubmatrix(std::vector<std::vector<int>> v)
{
	int m = v.size();
	if(m == 0) return 0;
	int n = v[0].size();

	int prefixSum[m][n];
	// construct prefix sum
	for(int i = 0; i<m; ++i){
		prefixSum[i][0] = v[i][0];
	}
	for(int j = 0; j<n; ++j){
		prefixSum[0][j] = v[0][j];
	}
	for(int i = 1; i<m; ++i){
		for(int j = 1; j<n; ++j){
			prefixSum[i][j] = prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1]+v[i][j];
		}
	}
	// for loop calculate largest sum with prefixSum O(n^4)
	int max = prefixSum[0][0];
	for(int i = 0; i<m; ++i){
		for(int j = 0; j<n; ++j){
			for(int k = -1; k<i; ++k){
				for(int t = -1; t<j; ++t){
					if(k == -1 || t == -1){
						max = std::max(max,  prefixSum[i][j]);
					}else{
						int tmp = prefixSum[i][j] - prefixSum[i][t] - prefixSum[k][j] + prefixSum[k][t];
						max = std::max(max, tmp);	
					}
				}
			}
		}
	}
	return max;
}

int largestSumOfSubmatrix_followUp(std::vector<std::vector<int>> v)
{
	int m = v.size();
	if(m == 0) return 0;
	int n = v[0].size();

	int prefixSum[m][n];
	// construct prefix sum
	for(int i = 0; i<m; ++i){
		prefixSum[i][0] = v[i][0];
	}
	for(int j = 0; j<n; ++j){
		prefixSum[0][j] = v[0][j];
	}
	for(int i = 1; i<m; ++i){
		for(int j = 1; j<n; ++j){
			prefixSum[i][j] = prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1]+v[i][j];
		}
	}
	int dp[n];
	int max = prefixSum[0][0];
	for(int j = 0; j<n; j++){
		max = std::max(max, prefixSum[0][j]);
	}
	for(int top = 1; top<m; top++){
		for(int bot = top; bot<m; bot++){
			for(int k = 0; k<n; ++k){
				if(k == 0){
					if(top == bot){
						dp[0] = prefixSum[bot][0];
					}else{
						dp[0] = prefixSum[bot][0] - prefixSum[top-1][0];
					}		
				}else{
					if(top == bot){
						dp[k] = dp[k-1]>0 ? prefixSum[bot][k] + dp[k-1] : prefixSum[bot][k];
					}else{
						dp[k] = dp[k-1]>0 ? prefixSum[bot][k] + dp[k-1] - prefixSum[top-1][k]: prefixSum[bot][k] - prefixSum[top-1][k];
					}
				}	
				max = std::max(dp[k], max);
			}
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}