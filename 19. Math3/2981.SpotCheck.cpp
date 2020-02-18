#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GCD(int a, int b) {
	if (b == 0)    return a;
	else    return GCD(b, a % b);
}

int main() {
	int N;
	cin >> N;
	int* number = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	sort(number, number + N);

	vector<int> euclidean;
	for (int i = 0; i < N - 1; i++) {
		euclidean.push_back(number[i + 1] - number[i]);
	}
	euclidean.erase(unique(euclidean.begin(), euclidean.end()), euclidean.end());
	sort(euclidean.begin(), euclidean.end());

	int gcd = GCD(euclidean[0], euclidean[1]);
	for (int i = 0; i < euclidean.size(); i++) {
		gcd = GCD(gcd, euclidean[i]);
	}
	
	for (int i = 2; i <= gcd; i++) {
		if (gcd % i == 0) cout << i << " ";
	}

	return 0;
}