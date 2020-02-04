#include <iostream>
using namespace std;

int main() {
	int N;
	int count = 0;
	cin >> N;

	while (N > 0) 
		N -= ++count;
	
	if(count%2 == 0)	cout << N + count << "/" << 1 - N << endl;
	else	cout << 1 - N << "/" << N + count << endl;

	return 0;
}
