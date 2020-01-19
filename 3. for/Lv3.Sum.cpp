#include <iostream>
using namespace std;

int main() {
    
    int num;
    int sumOfNum = 0;
    cin >> num;
	
    for(int i=0; i<num ; i++) {
        sumOfNum += (i+1); 
    }
    cout << sumOfNum;

	return 0;
}
