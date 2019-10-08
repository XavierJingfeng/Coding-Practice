#include <algorithm>
#include <vector>
#include <iostream>


// find the length of the longest ascending subarray
int longest(std::vector<int> array){
	int len = array.size();
	int M[len];
	M[0] = 1;
	int max = M[0];
	for(int i = 1; i<len; ++i){
		if(array[i]>array[i-1]){
			M[i] = M[i-1] + 1;
		}else
		{
			M[i] = 1;
		}
		max = std::max(M[i], max);
	}
	return max;
}



int main(int argc, char const *argv[]){

	
	std::vector<int> input({7,2,3,4,2,3,6,8,9,1,4});
	std::cout<<"longest length: "<<longest(input)<<std::endl;
	return 0;

}
