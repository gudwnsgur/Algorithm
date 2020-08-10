#include <iostream>
using namespace std;

int dp[11]{0, };

int main () {
    dp[1]=1; // 1
    dp[2]=2; // 1+1, 2 
    dp[3]=4; // 1+1+1, 2+1, 1+2, 3

    for(int i=4 ; i<=10 ; i++) 
        dp[i] = dp[i-3]+dp[i-2]+dp[i-1];
    
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int number;
        cin >> number;
        cout << dp[number] << endl;
    }        
    return 0;
}