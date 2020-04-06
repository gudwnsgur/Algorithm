#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long PrimeNumber(long long n) {
	long long least;
	//for (least = 2; least <= n/2; least++) {
	for (least = 2; least*least < n; least++) {
		if (n % least == 0)	break;
	}
	if (least*least > n) return 1;
	return n/least;
}

vector<int> solution(long long begin, long long end) 
{
	vector<int> answer;

	for (long long i = begin; i <= end; i++) {
		if (i == 1) answer.push_back(0);
		else {
			answer.push_back(PrimeNumber(i));
		}
	}
	return answer;
}