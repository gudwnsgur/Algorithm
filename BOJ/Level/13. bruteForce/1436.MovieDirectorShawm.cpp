#include <iostream>
#include <string>
using namespace std;

int main() {
	int count = 0;
	int N;
	cin >> N;
	int dstroyNumber = 665;
	
    while (count != N) {
		dstroyNumber++;
		if (to_string(dstroyNumber).find("666") <= 2147438647) {
			count++;
		}
	}
	cout << dstroyNumber;
	
	return 0;
}