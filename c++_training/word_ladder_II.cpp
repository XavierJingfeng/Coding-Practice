#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

vector<vector<string>> word_ladder_II(string startWord, string endWord, vector<string>& list)
{
	unordered_set<string> set(list.begin(), list.end());
	unordered_map<string, vector<string>> preNode_map;
	queue<string> q;
	q.push(startWord);
	bool flag = false;
	vector<string> builder;
	builder.push_back(startWord);
	vector<vector<string>> res;
	while(!q.empty() && !flag){
		int size = q.size();
		for(int i = 0; i<size; ++i){
			string cur = q.front();
			q.pop();
			if(cur == endWord){
				builder.push_back(cur);
				res.push_back(builder);
				flag =true;
			}
			


		}
	}


}

int main(int argc, char const *argv[])
{
	/* code */
	vector<string> v({"hot","dot","dog","lot","log","cog"});
	string startWord = "hit";
	string endWord = "cog";
	

	word_ladder_II_dfs(startWord, endWord, v);

	for(int i = 0; i<res.size(); ++i){
		for(int j = 0; j<res[0].size(); ++j){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}