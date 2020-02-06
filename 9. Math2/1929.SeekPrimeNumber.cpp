#include <iostream>
using namespace std;

const int MAX = 1000000;
bool prime[MAX+1];

int main() {
    int M, N;
    cin >> M >> N;
    prime[1] = true;
    for (int i=2; i*i<=MAX; i++) {
        if (!prime[i]) {
            for (int j=(i*i)%MAX; j<=MAX; j+=i) {
                prime[j] = true;
            }
        }
    }
    for (int i=M; i<=N; i++) {
        if (!prime[i]) cout << i << "\n";
    }
    return 0;
}