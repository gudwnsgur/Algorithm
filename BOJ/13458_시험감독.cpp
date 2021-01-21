#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n, B, C, answer=0;
	cin >> n;

	vector<long long> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	answer += n;
	for (int i = 0; i < n; i++) {
		A[i] -= B;
		if (A[i] > 0) {
			answer += A[i]%C ? A[i] / C + 1 : A[i] / C;
		}
	}
	cout << answer << endl;
	return 0;
}

