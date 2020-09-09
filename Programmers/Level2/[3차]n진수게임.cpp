#include <string>
#include <vector>
#include <iostream>
using namespace std;
char arr[1000001] = { ' ', };

string solution(int n, int t, int m, int p) {

	int st = 0;
	arr[0] = '0';
	arr[1] = '0';
	for (int i = 2; i <= t*m;) {
		string str = "";
		st++;
		int number = st;
		while (number > 0) {
			if (number % n >= 10) str += number % n + 55;
			else str += number % n + 48;
			number /= n;
		}
		for (int j = str.size()-1; j >=0; j--) {
			arr[i++] = str[j];
		}
	}
	string answer = "";
	for (int i = 0; i < t; i++) {
		answer += arr[p];
		p += m;
	}
	return answer;
}
int main() {

	cout << solution(16, 16, 2, 1);
	return 0;
}