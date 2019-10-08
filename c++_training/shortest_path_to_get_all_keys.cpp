#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <iostream>
#include <climits>
// 864. Shortest Path to Get All Keys
// We are given a 2-dimensional grid. "." is an empty cell, "#" is a wall, "@" is the starting point, ("a", "b", ...) are keys, and ("A", "B", ...) are locks.

// We start at the starting point, and one move consists of walking one space in one of the 4 cardinal directions.  We cannot walk outside the grid, or walk into a wall.  If we walk over a key, we pick it up.  We can't walk over a lock unless we have the corresponding key.

// For some 1 <= K <= 6, there is exactly one lowercase and one uppercase letter of the first K letters of the English alphabet in the grid.  This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

// Return the lowest number of moves to acquire all keys.  If it's impossible, return -1.

 

// Example 1:

// Input: ["@.a.#","###.#","b.A.B"]
// Output: 8
// Example 2:

// Input: ["@..aA","..B#.","....b"]
// Output: 6
 

// Note:

// 1 <= grid.length <= 30
// 1 <= grid[0].length <= 30
// grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
// The number of keys is in [1, 6].  Each key has a different letter and opens exactly one lock.




int shortest_path_to_get_all_keys(std::vector<std::string>& graph){
	int max_steps;
	int rows = graph.size();
	if (rows == 0) return 0;
	int cols = graph[0].length(); 

	std::queue<std::vector<int>> queue; // row = idx/rows,  cols = idx%rows;

	// get the starting point
	int numsOfKey = 0;
	int start = 0;
	for(int i = 0; i<rows; ++i){
		for(int j = 0; j<cols; ++j){
			if(graph[i][j] == '@'){
				start = i*cols+j;
			}else if(graph[i][j]>='a' && graph[i][j]<='z'){
				numsOfKey++;
			}
		}
	}
	std::cout<<"numsOfKey: "<<numsOfKey<<std::endl;
	std::vector<std::vector<std::vector<int>>> dist(rows, std::vector<std::vector<int>>(cols, std::vector<int>(1<<numsOfKey, INT_MAX))); // x, y, keys

	// bfs
	int dx[] = {0,1,0,-1};
	int dy[] = {1,0,-1,0};
	queue.push(std::vector<int>({start/cols, start%cols, 0}));
	dist[start/cols][start%cols][0] = 0;

	while(!queue.empty()){
		std::vector<int> curState = queue.front();
		int x = queue.front()[0];
		int y = queue.front()[1];
		int keys = queue.front()[2];
		
		std::cout<<x<<","<<y<<",keys: "<<keys<<std::endl;
		int d = dist[x][y][keys];
		std::cout<<"d: "<<d<<std::endl;
		queue.pop();
		if( keys == (1<<numsOfKey) - 1) return dist[x][y][keys];
		for(int i = 0; i<4; ++i){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if( nx>=0 && nx<rows && ny>=0 && ny<cols 
				&& graph[nx][ny] != '#'){

				char c = graph[nx][ny];
				if(c>='A' && c<='Z' && !(keys&1<<(c-'A')) ){
					continue;
				}
				int next_key = keys;
				if(c>='a' && c<='z') next_key |= 1<<(c-'a');

				if(dist[nx][ny][next_key] > d+1){
					dist[nx][ny][next_key] = d+1;
					queue.push(std::vector<int>({nx,ny,next_key}));
				}
			}
		}	
	}
	return -1;
}



int main(int argc, char const *argv[])
{
	/* code */
	std::vector<std::string> graph({"@...a",".###A","b.BCc"});
	std::cout<<shortest_path_to_get_all_keys(graph)<<std::endl;
	return 0;
}