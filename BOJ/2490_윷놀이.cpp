#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

char ch[5] = { 'D', 'C', 'B', 'A', 'E'};

int main() {
	for (int i = 0; i < 3; i++) {
		vector<int> v(4);
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> v[i];
			sum += v[i];
		}
		cout << ch[sum] << endl;
	}
}

