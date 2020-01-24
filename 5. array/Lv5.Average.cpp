#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
    cin >> num;

    double maxGrade, avg;
    avg =0;
	double *arr = new double[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
    maxGrade = arr[0];
    for (int i = 0; i < num; i++) {
		if(arr[i] > maxGrade) maxGrade = arr[i];
	}


    for (int i = 0; i < num; i++) {
		arr[i] = arr[i]/maxGrade*100;
        avg += arr[i];
	}
    cout << avg/num;

	return 0;
}
