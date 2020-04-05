#include <iostream>
using namespace std;

int main() {
	int N;
	int count = 0;
	int i = 1;
	cin >> N;

	do {
		if (N > i) {
			count++;
			i += count * 6;
		}
	} while (N > i);
	cout << count + 1 << endl;
	return 0;
}
