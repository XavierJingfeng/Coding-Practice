#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <unordered_set>

bool dictionary(std::string word, std::vector<std::string> dic){
	if(dic.size() == 0) return false;
	std::unordered_set<std::string> set;
	for(int i = 0; i<dic.size(); ++i){
		set.insert(dic[i]);
	}

	int word_len = word.length();
	bool can_cut[word_len+1];

	for(int i = 0; i<=word.length(); ++i){
		can_cut[i] = false;
	
	}

	for(int i = 1; i<=word.length(); ++i){
		
		if(set.find(word.substr(0, i)) != set.end())
		{
			can_cut[i] = true;
			continue;
		}
		for(int j = 1; j<i; ++j){
			if(can_cut[j] && set.find(word.substr(j, i-j)) != set.end()){
				can_cut[i] = true;
				break;
			}
		}
	}
	return can_cut[word_len];

};

int main(int argc, char const *argv[]){
	
	std::vector<std::string> dic;
	dic.push_back("bob");
	dic.push_back("cat");
	dic.push_back("rob");

	std::string s("bobcatbob");
	std::cout<<"can form? "<<dictionary(s, dic)<<std::endl;
	return 0;
}