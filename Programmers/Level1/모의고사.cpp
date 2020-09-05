#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int alice[5] = { 1, 2, 3, 4, 5 };
int bob[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int charlie[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
int point[3] = { 0, 0, 0 };

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	for (int i = 0; i<answers.size(); i++) {
		if (answers[i] == alice[i % 5])  point[0]++;
		if (answers[i] == bob[i % 8]) point[1]++;
		if (answers[i] == charlie[i % 10]) point[2]++;
	}

	int maxPoint = max(max(point[0], point[1]), point[2]);
	for (int i = 0; i < 3; i++) {
		if (point[i] == maxPoint) answer.push_back(i+1);
	}
	return answer;
}