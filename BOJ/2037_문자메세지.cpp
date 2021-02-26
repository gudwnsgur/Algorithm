#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;


int alphabet[27] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
					1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4, 1 };


int main() {
	string str;
	int r, w;
	cin >> r >> w;
	int cnt = 0;
	getline(cin, str);
	getline(cin, str);

	for (int i = 0; i < 27; i++) alphabet[i] *= r;

	for (int i = 0; i < str.size(); i++) {
		int cur = str[i];
		if (str[i] == ' ') cur = 'Z' + 1;

		if (i != 0) {
			if (((str[i - 1] == 'A' || str[i - 1] == 'B' || str[i - 1] == 'C') &&
				(str[i] == 'A' || str[i] == 'B' || str[i] == 'C')) ||

				((str[i - 1] == 'D' || str[i - 1] == 'E' || str[i - 1] == 'F') &&
				(str[i] == 'D' || str[i] == 'E' || str[i] == 'F')) ||

				((str[i - 1] == 'G' || str[i - 1] == 'H' || str[i - 1] == 'I') &&
				(str[i] == 'G' || str[i] == 'H' || str[i] == 'I')) ||

				((str[i - 1] == 'J' || str[i - 1] == 'K' || str[i - 1] == 'L') &&
				(str[i] == 'J' || str[i] == 'K' || str[i] == 'L')) ||

				((str[i - 1] == 'M' || str[i - 1] == 'N' || str[i - 1] == 'O') &&
				(str[i] == 'M' || str[i] == 'N' || str[i] == 'O')) ||

				((str[i - 1] == 'P' || str[i - 1] == 'Q' || str[i - 1] == 'R' || str[i-1] == 'S') &&
				(str[i] == 'P' || str[i] == 'Q' || str[i] == 'R' || str[i] == 'S')) ||

				((str[i - 1] == 'T' || str[i - 1] == 'U' || str[i - 1] == 'V') &&
				(str[i] == 'T' || str[i] == 'U' || str[i] == 'V')) ||

				((str[i - 1] == 'W' || str[i - 1] == 'X' || str[i - 1] == 'Y' || str[i-1] == 'Z') &&
				(str[i] == 'W' || str[i] == 'X' || str[i] == 'Y' || str[i] == 'Z'))
				) {
				cnt += w;
			}
		}

		cnt += alphabet[cur - 65];
	}
	cout << cnt << endl;
	return 0;
}



