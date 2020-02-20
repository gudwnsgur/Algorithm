#include <iostream>
using namespace std;

int GCD (int a, int b) {
    if(b == 0 ) return a;
    return GCD(b, a%b);
}

int main () {
    int N;
    cin >> N;
    int *ring = new int[N];
    for(int i=0; i<N ; i++) {
        cin >> ring[i];
    }

    for(int i=1 ; i<N ; i++) 
        cout << ring[0]/GCD(ring[0], ring[i]) << "/" << ring[i]/GCD(ring[0], ring[i]) << "\n";

    return 0;
}