#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(int n) {
	int num = n;
	int answer = 0, cntOne=0;
	while (n > 0) {
		if (n % 2 ) cntOne++;
		n /= 2;
	}
	
	for (int i = num + 1; ; i++) {
		int tmp = i, localOne=0;
		while (tmp > 0) {
			if (tmp % 2 ) localOne++;
			tmp /= 2;
		}
		if (localOne == cntOne) return i;
	}
}