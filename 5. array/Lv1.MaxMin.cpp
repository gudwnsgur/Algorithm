#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int num, max, min;
    int *arr;

    cin >> num;
    arr = new int[num];
    for(int i=0; i<num; i++) {
        cin >> arr[i];
    }
    max = min = arr[0];

    for(int i=0 ; i<num ; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i]; 
    }
    
    cout << min << " " << max;

	return 0;
}
