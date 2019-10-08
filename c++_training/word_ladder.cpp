#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

// Note:

// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
// Example 1:

// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// Output: 5

// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Example 2:

// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]

// Output: 0

// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.


bool cantransform(string s1, string s2){
	if(s1.length() == 0 || s2.length() == 0) return false;
	int i = 0;
	int cnt = 0;
	for(int i = 0; i<s1.length(); ++i){
		if(s1[i] != s2[i]) cnt++;
		if(cnt>1) return false;
	}
	return true;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> set(wordList.begin(), wordList.end());
	queue<string> q;
	q.push(beginWord);
	int layer = 1;
	while(!q.empty()){
		int size = q.size();
		for(int i = 0; i<size; ++i){
			string cur = q.front();
			q.pop();
			// generate nodes
			if(cur == endWord) return layer;
			set.erase(cur);
			for(int j = 0; j<cur.length(); ++j){
				char c = cur[j];
				for(int k = 0; k<26; ++k){
					cur[j] = 'a' + k;
					if(set.find(cur) != set.end()){
						q.push(cur);
					}
				}
				cur[j] = c;
			}
		}
		layer++;
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	vector<string> wordlist({"hot","dot","dog","lot","log","cog"});
	string beginWord = "hit";
	string endWord = "cog";
	cout<<ladderLength(beginWord, endWord, wordlist)<<endl;
	
	return 0;
}