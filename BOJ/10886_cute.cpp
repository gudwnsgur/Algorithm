#include <iostream>
using namespace std;

int main () {
    int n, number;
    int zeroCnt=0, oneCnt=0;
    cin >> n;

    
    for(int i=0; i<n; i++) {
        cin >> number;
        number ? oneCnt++ : zeroCnt++;
    }
    cout << (oneCnt>zeroCnt?"Junhee is cute!":"Junhee is not cute!") << endl;
    return 0;
}