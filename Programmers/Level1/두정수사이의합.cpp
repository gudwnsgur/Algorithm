#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
	long long answer;
	if (a == b) return a;

	int cnt = (a>b ? a : b) - (a<b ? a : b) + 1;

	if (cnt % 2 != 0) answer = (long long)((a + b) / 2)*cnt;
	else   answer = (long long)(a + b)*(cnt / 2);
	return answer;
}