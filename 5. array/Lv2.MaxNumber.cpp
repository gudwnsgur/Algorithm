#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int *arr = new int[9];
    int max, maxIndex;

    for(int i=0; i<9 ; i++) {
        cin >> arr[i];
    }

    max = arr[0];
    maxIndex = 1;
    
    for(int i=0; i<9 ; i++) {
        if(arr[i] > max) {
            max = arr[i];
            maxIndex = i+1;
        }
    }
    cout << max << "\n" << maxIndex;

	return 0;
}
