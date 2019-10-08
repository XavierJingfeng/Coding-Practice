#include <vector>
#include <iostream>

std::vector<int> largestSum(std::vector<int> &a)
{
	std::vector<int> res;
	int curmax = a[0];
	int globalmax = a[0];
	int globalleft = 0;
	int globalright = 0;
	int curleft = 0;
	int curright = 0;
	for(int i = 1; i<a.size(); ++i){
		if(curmax>0){
			curmax=curmax+a[i];
			curright++;
		}else{
			curmax = a[i];
			curleft = i;
			curright = curleft;
		}
		if(curmax>globalmax){
			globalmax = curmax;
			globalleft = curleft;
			globalright = curright;
		}
	}
	res.push_back(globalmax);
	res.push_back(globalleft);
	res.push_back(globalright);
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<std::vector<int>> v({
		{1,20,4,10,-1,-2,10,-1,-100,10,20},
		{-1,-2,-3,4,5,-10}
	});

	for(auto a: v) std::cout<<largestSum(a)[0]<<","<<largestSum(a)[1]<<","<<largestSum(a)[2]<<std::endl;
	return 0;
}