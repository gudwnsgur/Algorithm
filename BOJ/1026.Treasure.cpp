#include <iostream>
#include <algorithm>
using namespace std;


int main () {
    int n;
    cin >> n;
    int* A = new int[n];
    int* B = new int[n];

    for(int i=0; i<n ; i++) cin >> A[i];
    for(int i=0; i<n ; i++) cin >> B[i];

    sort(A,A+n);
    sort(B,B+n, greater<int>());

    int leastNum = 0;

    for(int i=0; i<n ; i++) leastNum += A[i]*B[i];
    cout << leastNum;
    

    return 0;
}