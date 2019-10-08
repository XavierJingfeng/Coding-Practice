#include <algorithm>
#include <vector>
#include <iostream>
#include "assert.h"


bool jump(int* array, int size){

	bool M[size];
	M[0] = true;
	for(int i = 0; i<size; ++i){
		for(int j = 0; j<i; ++j){
			if(M[j] && array[j] + j >= i)
			{
				M[i] = true;
				break;
			}else M[i] = false;
		}
	}
	return M[size-1];
}

int main(int argc, char const *argv[]){
	int a[] ={2,3,1,0,0	};
	bool res = jump(a, sizeof(a)/sizeof(a[0]));
	assert(res);
	return 0;
}	