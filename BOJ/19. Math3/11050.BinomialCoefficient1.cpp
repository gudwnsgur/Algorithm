#include <iostream>
using namespace std;

int factorial(int r) {
    if(r == 1) return 1;
    return r*factorial(r-1);
}
int permutation(int n, int r) {
    if(r==0) return 1;
    return n*permutation(n-1, r-1);
}
int combination(int n, int r) {
    return permutation(n,r)/factorial(r);
}

int main () {
    int N, K;
    cin >> N >> K;
    cout << combination(N, K);
    return 0;
}