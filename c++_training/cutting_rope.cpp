#include <algorithm>
#include <vector>
#include <iostream>

int cutting_rope(int n){
	int M[n+1];
	M[0] = 0;
	M[1] = 0;
	if (n == 0) return 0;
	int max = 0;
	for(int i = 2; i<n+1; ++i){
		for(int j = 1; j<i; ++j){
			max = std::max( max, std::max(M[j], j)*(i-j) );
		}
		M[i] = max;
	}
	return M[n];

}

int main(int argc, char const *argv[]){

	std::cout<<"max cut: "<<cutting_rope(2)<<std::endl;
	return 0;
}