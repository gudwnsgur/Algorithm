#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leftDP, rightDP;

int solution(vector<int> a) {
	int answer = 0;
	leftDP = vector<int>(a.size());
	rightDP = vector<int>(a.size());
	leftDP[0] = 1000000001;
	rightDP[a.size() - 1] = 1000000001;

	for (int i = 1; i < a.size(); i++)
		leftDP[i] = min(leftDP[i - 1], a[i - 1]);
	for (int i = a.size() - 2; i >= 0; i--)
		rightDP[i] = min(rightDP[i + 1], a[i + 1]);

	for (int i = 0; i < a.size(); i++) {
		if (a[i] < leftDP[i] || a[i] < rightDP[i]) answer++;
	}
	return answer;
}