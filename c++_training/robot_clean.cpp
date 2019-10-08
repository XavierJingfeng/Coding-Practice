#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <string>


struct Robot{
	Robot(){};
	void clean(){}
	void turn_left(){}
	bool move(){}
	void turn_right(){}
};

void recover(Robot& robot){
	robot.turn_right();
	robot.turn_right();
	robot.move();
	robot.turn_left();
	robot.turn_left();
}

void dfs(Robot& robot, int x, int y, int dir, std::unordered_set<std::string>& set){
	robot.clean();
	std::string visited = x+","+y;
	set.insert(visited);

	for(int i = 0; i<4; ++i){
		int newdir = (dir+i)%4;
		std::string next = x+","+y;
		if(robot.move() && set.find(next)==set.end()){
			dfs(robot, newx, newy, newdir, set);
			recover(robot);
		}
		robot.turn_right();
	}
}

void clean_room(Robot& robot){
	std::unordered_set<std::string> set;
	dfs(robot, 0, 0, 0, set);
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}