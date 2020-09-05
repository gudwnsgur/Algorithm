#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int dice[6];
long long n;

long long solution() {
	int space[3];
	int tmp = 51;

	for (int i = 0; i < 6; i++)
		if (tmp > dice[i]) tmp = dice[i];
	space[0] = tmp;

	tmp = 101;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			if ((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3));
			else tmp = min(tmp, dice[i] + dice[j]);
		}
	}
	space[1] = tmp;
	space[2] = min(dice[0], dice[5]) + min(dice[1], dice[4]) + min(dice[2], dice[3]);

	return (long long)space[2]*4 + 
		(long long)space[1]*(2*n-3)*4 + 
		(long long)space[0]*(((n-2)*(n-1)*4) + (n-2)*(n-2));
}

int main() {
	int maxNum = 0 , sum =0;
	cin >> n;

	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
		sum += dice[i];
		maxNum = max(maxNum, dice[i]);
	}
	if (n == 1) cout << (sum - maxNum) << endl;
	else cout << solution() << endl;
	return 0;
}