#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, count;
	int multi;

	int *arr = new int[42];
	for (int i = 0; i < 42; i++) {
		arr[i] = 0;
	}

	for (int i=0; i<10 ; i++) {
        cin >> num;
        arr[num%42]++;
    }

    count =0;
	for (int i = 0; i < 42; i++) {
		if(arr[i] !=0) count++;
	}
    cout << count;
	return 0;
}
