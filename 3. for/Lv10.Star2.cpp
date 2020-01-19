#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
	cin >> n;
	for(int i=0 ; i<n ; i++) {
		int j=0;
		for(j ; j < (n-i-1) ; j++) {
			cout << " ";
		}
		for(j; j<n; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}
