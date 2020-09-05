#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	int result;
	int time[3] = { 0, };

	cin >> result;
	time[0] = result / 300;	  result %= 300;
	time[1] = result / 60;    result %= 60;
	time[2] = result / 10;    result %= 10;
	
	if (result) cout << "-1" << endl;
	else cout << time[0] << ' ' << time[1] << ' ' << time[2] << endl;
	return 0;
}