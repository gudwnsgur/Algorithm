#include <string>
#include <vector>
using namespace std;

int solution(int num) {
	long n = (long)num;

	for (int i = 0; i < 500; i++) {
		if (n == 1) return i;
		
		n = ( (n % 2) ? n * 3 + 1 : n / 2);
	}
	return -1;
}