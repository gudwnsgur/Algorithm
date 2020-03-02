#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int a, int b) {
	int month[12] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
	string answer[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

	return answer[ (month[a - 1] + b) % 7 ];
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << solution(a, b);
	return 0;
}
