#include <iostream>
using namespace std;

int solution(int num) {
	int cnt = 0;
	long n = (long)num;
	for(int i=0  ; i<500 ; i++) {
		if (n == 1) return i;
		
        if(n%2==0 )  n /= 2; 
        else  n = n * 3 + 1;
	}
	return -1;
}

int main() {
	int n;
    cin >> n;
	cout << solution(n);
	return 0;
}