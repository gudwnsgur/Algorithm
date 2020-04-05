#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	int count = 1;
	cin >> A >> B >> C;
    
    int X;
    if((C-A)%(A-B) == 0 ) X=(C-A)/(A-B);
    else X = (C-A)/(A-B)+1;
    
	cout <<  X+1;
	return 0;
}
