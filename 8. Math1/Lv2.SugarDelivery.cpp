#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    if(N ==1 || N==2|| N==4 || N==7) cout << -1;
    else if(N%5 == 1) cout << (N-6)/5 + 2;
    else if(N%5 == 2)  cout << (N-12)/5 + 4;
    else if(N%5 == 3)  cout << (N-3)/5 +1;
    else if(N%5 == 4)  cout << (N-9)/5 +3;
    else cout << N/5;

	return 0;
}
