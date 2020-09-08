#include <string>
#include <vector>
#include <iostream>
using namespace std;
int cnt = 0;
char num[10];
bool visited[10] = { false, };
bool checked[10000000] = { false, };
string number;

bool isPrimeNumber(int num) {
	checked[num] = true;
	if (num == 1 || num == 0) return false;
	for (int i = 2; i < num; i++) {
		if (!(num%i)) return false;
	}
	return true;
}
void dfs(int length, int n) {
	if (length == n) {
		string str = "";
		for (int i = 0; i < length; i++) str += num[i];
		if (!checked[stoi(str)]) {
			if (isPrimeNumber(stoi(str))) cnt++;
		}return;
	}
	for (int i = 0; i < number.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			num[length] = number[i];
			dfs(length + 1, n);
			visited[i] = false;
		}
	}
}

int solution(string numbers) {
	number = numbers;
	int n = numbers.size();
	for (int i = 1; i <= n; i++) {
		dfs(0, i);
	}
	return cnt;
}
int main() {
	cout << solution("011") << endl;
	return 0;
}