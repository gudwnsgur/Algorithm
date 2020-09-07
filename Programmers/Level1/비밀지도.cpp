#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

	vector<string> answer;

	bool* binary1 = new bool[n];
	bool* binary2 = new bool[n];
	bool* newBi = new bool[n];

	for (int i = 0; i < n; i++) {
		int first = arr1[i];
		int second = arr2[i];

		for (int j = 0; j < n; j++) {
			if (first >= pow(2, n - j - 1)) {
				binary1[j] = true;
				first -= pow(2, n - j - 1);
			}
			else { binary1[j] = false; }

			if (second >= pow(2, n - j - 1)) {
				binary2[j] = true;
				second -= pow(2, n - j - 1);
			}
			else { binary2[j] = false; }
		}

		for (int j = 0; j < n; j++) {
			if (binary1[j] || binary2[j]) newBi[j] = true;
			else newBi[j] = false;
		}
		string line;
		for (int j = 0; j < n; j++) {
			if (newBi[j]) line.push_back('#');
			else line.push_back(' ');
		}
		answer.push_back(line);
	}
	return answer;
}
int main() {
	int n = 5;
	vector<int> v1;
	vector<int> v2;

	v1.push_back(27);
	v1.push_back(3);
	v1.push_back(23);
	v1.push_back(1);
	v1.push_back(21);

	v2.push_back(3);
	v2.push_back(23);
	v2.push_back(28);
	v2.push_back(3);
	v2.push_back(21);

	vector<string> v = solution(n, v1, v2);
	for (string line : v) {
		cout << line << endl;
	}
	return 0;
}