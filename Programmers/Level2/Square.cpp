#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

long long solution(int w, int h)
{
	long long answer;
	long lw = (long)w, lh = (long)h;
	int cnt = gcd(w, h);
	if (cnt == 1) answer = lw * lh - (lw + lh) + 1;
	else {
		answer = lw * lh - (lw / cnt + lh / cnt - 1) * cnt;
	}
	return answer;
}
int main() {
	cout << solution(7, 13);
	return 0;
}