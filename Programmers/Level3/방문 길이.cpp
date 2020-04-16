#include <string>
using namespace std;

bool visited[11][11][4]{ false, }; // [4] : 방향
// 0 up, 1 down, 2 left, 3 right
 

int solution(string dirs) 
{
	int answer = 0;
	int x = 5, y = 5; // 중점
	for (int i = 0; i < dirs.size(); i++) {
		if (dirs[i] == 'U' && y != 0) {
			y--; 
			if (!visited[x][y][1]) {
				visited[x][y+1][0] = true;	visited[x][y][1] = true;
				answer++;
			}
		}
		else if (dirs[i] == 'D' && y != 10) {
			y++; 
			if (!visited[x][y][0]) {
				visited[x][y-1][1] = true;    visited[x][y][0] = true;
				answer++;
			}
		}
		else if (dirs[i] == 'L' && x != 0) {
			x--; 
			if (!visited[x][y][3]) {
				visited[x+1][y][2] = true;    visited[x][y][3] = true;
				answer++;
			}
		}
		else if(dirs[i] == 'R' && x != 10)  {  
			x++; 
			if (!visited[x][y][2]) {
				visited[x-1][y][3] = true;    visited[x][y][2] = true;
				answer++;
			}
		}
	}
	return answer;
}