#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;
 
string solution(int n) {
	vector<int> v(n);
	int one = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] == 1) one++;
	}
	if (one%2 || (one==0 && n%2)) return "NO";
	return "YES";
}
int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		cout << solution(n) << endl;
	}
	return 0;
}
