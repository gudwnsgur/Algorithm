#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[21] = { false, };

long long factorial(long long n) {
	if (n == 1) return 1;
	return n*factorial(n - 1);
}

vector<int> solution(int n, long long k) {
	vector<int> answer;
	k--;

	long long fac = factorial(n - 1);
	for (int i = 0, div = n - 1; i < n - 1; i++, div--) {
		int loc = k / fac; // 1

		int j = 0, tmp = 0;
		for (; j < n; j++) {
			if (!visited[j] && tmp == loc) break;
			else if (!visited[j]) tmp++;
		}

		visited[j] = true;
		answer.push_back(j + 1);
		k -= fac*(k / fac);
		fac /= div;
	}
	for (int i = 0; i < n; i++) 
		if (!visited[i]) answer.push_back(i + 1);
	return answer;
}

int main() {
	vector<int> a = solution(4, 11);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}cout << endl;
	return 0;
}