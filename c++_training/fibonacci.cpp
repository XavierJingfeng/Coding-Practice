#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

int fiboN(int n, std::unordered_map<int, int> map){
	if(n == 0 || n == 1) return n;
	auto it = map.find(n);
	if(it != map.end()){
		return it->second;
	}

	int a = fiboN(n-1, map);
	int b = fiboN(n-2, map);
	map.insert(std::make_pair(n,a+b));
	return a+b;

}

int main(int argc, char const *argv[])
{
	
	std::unordered_map<int , int> map;
	std::cout<<"fibonacci(7) = "<<fiboN(7, map)<<std::endl;
	return 0;
}