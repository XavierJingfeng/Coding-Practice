#include <queue>
#include <algorithm>
#include <iostream>
#include <functional>


class quick_median
{
private:
	std::priority_queue<int> max_heap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
	double mid;
public:
	quick_median(){
		mid = 0;
	}
	~quick_median(){}

	void push(int key){
		if(max_heap.empty() && min_heap.empty()){
			max_heap.push(key);
			mid = key;
		}else{


			if(key>=mid){
				min_heap.push(key);
				while(min_heap.size() > max_heap.size()+1){
					int top = min_heap.top();
					min_heap.pop();
					max_heap.push(top);
				}
			}else{
				max_heap.push(key);
				while(max_heap.size() > min_heap.size()+1){
					int top = max_heap.top();
					max_heap.pop();
					min_heap.push(top);
				}
			}

			if(max_heap.size() == min_heap.size()){
				mid = ((double)max_heap.top()+ (double)min_heap.top())/2;
			}else if(max_heap.size()>min_heap.size()){
				mid = max_heap.top();
			}else{
				mid = min_heap.top();
			}
		}
	}
	double find_mid(){
		return mid;
	}
};

int main(int argc, char const *argv[])
{
	
	quick_median q;
	srand(time(NULL));
	for(int i = 0; i<10; i++){
		int num = rand()%10;
		q.push(num);
		std::cout<<"push: "<<num<<std::endl;
		std::cout<<"mid: "<<q.find_mid()<<std::endl;
	}	

	return 0;
}
