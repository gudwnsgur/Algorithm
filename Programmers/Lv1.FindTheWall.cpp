#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

	vector<string> answer;

	int* binary1 = new int[n];
	int* binary2 = new int[n];
	for (int i = 0; i < n; i++) {
		binary1[i] = 0;	binary2[i] = 0;
	}

	for (int k = 0; k < n; k++) {
		int* newBi = new int[n];


		for (int i = 0; i < n; i++) {
			newBi[i] = 0;

			binary1[i] = 0;
			binary2[i] = 0;

			binary1[i] = arr1[k] % 2;
			arr1[k] = arr1[k] / 2;

			binary2[i] = arr2[k] % 2;
			arr2[k] = arr2[k] / 2;
			if (binary1[i] == 1 || binary2[i] == 1) newBi[i] = 1;
			
		}
		int result = 0, mul = 1;
		for (int i = n-1; i >= 0; i--) {
			result += newBi[i]*mul;
			mul *= 2;
		}
		answer[k] = result;
	}
	return answer;
}