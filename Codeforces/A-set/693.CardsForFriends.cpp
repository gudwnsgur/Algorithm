#include <iostream>
#include <string>
#define endl '\n'
using namespace std;
 
string solution(int w, int h, int n) {
	long long area = w*h;
	int result = 1;
	while (! (area % 2) ) {
		result *= 2;
		area /= 2;
	}
	return result >= n ? "YES" : "NO";
}
int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int w, h, n;
		cin >> w >> h >> n;
		cout << solution(w, h, n) << endl;
	}
	return 0;
}


