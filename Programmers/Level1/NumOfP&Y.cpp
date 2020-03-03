#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	int pCnt = 0, yCnt = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'p' || s[i] == 'P') pCnt++;
		if (s[i] == 'y' || s[i] == 'Y') yCnt++;
	}
	return pCnt == yCnt;
}