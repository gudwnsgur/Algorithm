#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

bool existed[21] = { false, };

int main() {
	ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std:: cout.tie(NULL);

	string op;
	int n, num;
	cin >> n;
	while (n--) {
		cin >> op;
		if (op != "all" && op != "empty") cin >> num;
		string s = op.substr(0, 3);

		if (s == "add") existed[num] = true;
		else if (s == "rem") existed[num] = false;
		else if (s == "che") cout << (existed[num] ? 1 : 0) << endl;
		else if (s == "tog") existed[num] = (existed[num] ? false : true);
		else if (s == "all") for (int i = 1; i <= 20; i++) existed[i] = true;
		else for (int i = 1; i <= 20; i++) existed[i] = false;
	}
	return 0;
}

