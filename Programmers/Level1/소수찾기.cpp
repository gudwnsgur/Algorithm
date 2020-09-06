#include <iostream>
using namespace std;

int solution(int n) {
    int count = 0;
    bool* prime = new bool[n + 1];
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }

    for (int i = 2; i*i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i]) count++;
    }
    return count;
}