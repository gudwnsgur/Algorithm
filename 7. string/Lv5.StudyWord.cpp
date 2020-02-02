#include <iostream>
#include <string>
using namespace std;

int main() {
	int i;
	string str;
	cin >> str;
	int* alphabet = new int[26];
	for (i = 0; i < 26; i++) {
		alphabet[i] = 0;
	}

	for (i = 0; i < str.length(); i++) {
		if ((int)str[i] > 95)
			alphabet[(int)str[i] - 97]++;
		else
			alphabet[(int)str[i] - 65]++;
	}
	
	char outputCh = 'A';
	int max = alphabet[0];
	
	for (i = 0; i < 26; i++) {
		if (max < alphabet[i]) {
			max = alphabet[i];
			outputCh = (char)(i + 65);
		}
	}
	for (i = 0; i < 26; i++) {
		if (max == alphabet[i] && (char)(i + 65) != outputCh) {
			outputCh = '?'; 
			break;
		}
	}
	cout << outputCh;
	
	return 0;
}