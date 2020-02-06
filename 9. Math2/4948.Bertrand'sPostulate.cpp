#include <iostream>
using namespace std;

bool prime[123456*2+1] = {false, };

int main () {

    for(int i=2 ; i*i  <= 123456*2 ; i++) {
        if(prime[i] == false)
            for(int j = i*i; j<=123456*2 ; j+=i) 
                prime[j] =true;
    }
    int n;
    while(cin >> n) {
        if(n==0 )break;
        int count = 0;
        for(int i=n+1 ; i<=2*n ; i++) {
            if(prime[i] == false) count ++;
        }
        cout << count << endl;
    }
    return 0;
}