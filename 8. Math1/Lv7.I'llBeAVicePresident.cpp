#include <iostream>
using namespace std;

int main(){
	int arr[15][15];
	arr[0][0] = 1;
	for (int i = 1; i<15; i++){
		arr[0][i] = i+1;
		arr[i][0] = 1;
	}
	for (int i = 1; i<15; i++){
		for (int j = 1; j<15; j++){
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}
	int size, n, k;
	cin >> size;
	for (int i = 0; i<size; i++){
		cin >> n >> k;
		cout << arr[n][k - 1] << endl;
	}
}
