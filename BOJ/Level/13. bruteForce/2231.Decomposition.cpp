#include <iostream>
using namespace std;
int main ( ) {
    int number;
    cin >> number;

    int creator= 1;
    while(1) {
        int decomposition = creator;
        int sum = creator;

        while(decomposition) {
            sum += decomposition%10;
            decomposition /=10;
        }
        if(creator == number || sum == number)
            break;
        creator++;
    }
    if(creator == number ) cout << 0 << endl;
    else cout << creator << endl; 
    return 0;
}