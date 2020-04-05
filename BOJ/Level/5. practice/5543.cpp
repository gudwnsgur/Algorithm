#include <iostream>
using namespace std;
int main() {
	int arr[5], min1=2001, min2=2001;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
        if(i<=2 && arr[i]<min1) min1=arr[i];
        if(i>2 && arr[i]<min2) min2=arr[i]; 
	}
	cout << (min1+min2)-50;
	return 0;
}