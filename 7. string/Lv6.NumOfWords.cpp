#include <iostream>
#include <string>
using namespace std;

int main() {
    int count = 1;
	string str;
	getline(cin, str);

    if(str[0] == ' ') count--;
    if(str[str.length()-1]==' ') count--;

    for(int i=0; str.length() ; i++) {
        if(str[i]==' ') count++;
    }
    cout << count;
	return 0;
}