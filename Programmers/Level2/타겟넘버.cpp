#include <string>
#include <vector>
#include <iostream>
using namespace std;
int cnt = 0;
char op[25];
int number[25];

bool isTargeted(int n, int target) {
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (op[i] == '+') num += number[i];
		else num -= number[i];
	}
	if (target == num) return true;
	return false;
}

void dfs(int length, int n, int target) {
	if (length == n) {
		if (isTargeted(n, target)) cnt++;
		return;
	}
	op[length] = '+';
	dfs(length + 1, n, target);
	op[length] = '-';
	dfs(length + 1, n, target);
}

int solution(vector<int> numbers, int target) {
	for (int i = 0; i < numbers.size(); i++) number[i] = numbers[i];
	dfs(0, (int)numbers.size(), target);
	return cnt;
}
int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	cout << solution(v, 3) << endl;
	return 0;
}