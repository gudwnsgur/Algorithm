#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B;
	cin >> A >> B ;

	while(A !=0 || B!=0) {
		cout << A+B << "\n";
		cin >> A >> B;
	}
	return 0;
}
