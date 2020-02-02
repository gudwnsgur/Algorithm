#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B;
    int max, reverse;
    cin >> A >> B;
    if(A%10 > B%10) max = A;
    else if(A%10 < B%10) max = B;
    else {
        if( (A/10)%10 > (B/10)%10 ) max = A;
        else if((A/10)%10 < (B/10)%10  ) max =B;
        else {
            if( A/100 > B/100 ) max = A;
            else max = B;
        }
    }

    reverse = (max%10)*100 + ((max/10)%10)*10 + max/100;    
    cout << reverse;
	return 0;
}