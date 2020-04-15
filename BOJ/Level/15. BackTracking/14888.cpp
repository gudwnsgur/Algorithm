#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> result;
char op[10];
bool visited[10]{ false, };

void calculation(vector<int> num) {
	result.push_back(num[0]);
	for (int i = 1; i < num.size(); i++) {
		if (op[i - 1] == '+') result.back() += num[i];
		else if (op[i - 1] == '-') result.back() -= num[i];
		else if (op[i - 1] == '*') result.back() *= num[i];
		else result.back() /= num[i];
	}
}

void dfs(int length, int n, vector<int> num, int plus, int minus, int multi, int mod) {
	if (length == n) {
		// for (int i = 0; i < n; i++) cout << op[i] << ' '; 
		calculation(num);
		return; // 연산자를 다 사용했다면 계산
	}
	if (plus) {
		op[length] = '+';
		dfs(length + 1, n, num, plus - 1, minus, multi, mod);
	}
	if (minus) {
		op[length] = '-';
		dfs(length + 1, n, num, plus, minus - 1, multi, mod);
	}
	if (multi) {
		op[length] = '*';
		dfs(length + 1, n, num, plus, minus, multi - 1, mod);
	}
	if (mod) {
		op[length] = '/';
		dfs(length + 1, n, num, plus, minus, multi, mod - 1);
	}

}

int main() {
	int n;
	int plus, minus, multi, mod;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) cin >> num[i];
	cin >> plus >> minus >> multi >> mod;

	dfs(0, n - 1, num, plus, minus, multi, mod); // n-1개의 연산자

	// for (int i = 0; i < result.size(); i++) cout << result[i] << ' ';
	
	sort(result.begin(), result.end());
	cout << result[result.size() - 1] << endl << result[0];
	return 0;
}