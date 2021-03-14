#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define endl '\n'
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		int result = 0;
		cin >> a >> b;
		vector<int> A(a), B(b);
		for (int i = 0; i < a; i++) cin >> A[i];
		for (int i = 0; i < b; i++) cin >> B[i];
		sort(A.begin(), A.end(), greater<int>());
		sort(B.begin(), B.end(), greater<int>());

		int idx = 0;
		for (int i = 0; i < a; i++) {
			while (idx < b && A[i] <= B[idx]) idx++;
			if (idx >= b) break;
			result += (b - idx);
		}
		cout << result << endl;
	}
	return 0;
}

