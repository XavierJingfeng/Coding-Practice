#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	int horizonal_distance;
	TreeNode(int v){
		val = v;
		left = right = nullptr;
		horizonal_distance = 0;
	}
	
};

void vertical_print(TreeNode* root){
	// level order traverse the binary tree
	std::queue<TreeNode*> q;
	q.push(root);
	std::unordered_map<int, std::vector<TreeNode*> > map;
	std::vector<TreeNode*> r;
	r.push_back(root);
	map.insert(std::make_pair(root->horizonal_distance, r));
	while(!q.empty()){
		int size = q.size();
		for(int i = 0; i<size; ++i){
			TreeNode* cur = q.front();
			q.pop();
			if(cur->left != nullptr){
				int hd = cur->horizonal_distance-1;
				cur->left->horizonal_distance = hd;
				
				// insert the node to the map
				auto it = map.find(hd);
				if(it == map.end()){
					std::vector<TreeNode*> v;
					v.push_back(cur->left);
					map.insert(std::make_pair(hd, v));	
				}else{
					it->second.push_back(cur->left);
				}
				// end of insert node
				
				q.push(cur->left);
			}
			if(cur->right != nullptr){
				int hd = cur->horizonal_distance+1;
				cur->right->horizonal_distance = hd;

				// insert the node to the map
				auto it = map.find(hd);
				if(it == map.end()){
					std::vector<TreeNode*> v;
					v.push_back(cur->right);
					map.insert(std::make_pair(hd, v));	
				}else{
					it->second.push_back(cur->right);
				}
				// end of insert node
				q.push(cur->right);
			}
		}
	}
	std::vector<int> array;
	for(auto it : map){
		int hd = it.first;
		array.push_back(hd);
	}
	sort(array.begin(), array.end());
	for(int i = 0; i<array.size(); ++i){
		auto it  = map.find(array[i]);
		if(it != map.end()){
			int size = it->second.size();
			for(int j = 0; j<size; ++j){
				std::cout<<it->second[j]->val<<" ";
			}
			std::cout<<std::endl;
		}

	}
}

int main(int argc, char const *argv[])
{
	// build tree
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	
	TreeNode* left = root->left;
	left->left = new TreeNode(4);
	left->right = new TreeNode(5);
	
	TreeNode* right = root->right;
	right->left = new TreeNode(6);
	right->right = new TreeNode(7);

	right->right->left = new TreeNode(8);

	//test
	vertical_print(root);

	return 0;
}