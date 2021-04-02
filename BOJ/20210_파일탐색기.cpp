#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int priority[124] = { 0, };
int n;
vector<string> arr;

bool isNum(char ch) {
	return ch >= '0' && ch <= '9';
}

bool compare(string a, string b) {
	for (int i = 0, j = 0; i < a.size() && j < b.size(); i++, j++) {
		if (isNum(a[i]) && isNum(b[i])) {
			string aNum = "", bNum = "";
			while (i < a.size() && isNum(a[i])) {
				aNum.push_back(a[i]);
				i++;
			}
			i--;
			while (j < b.size() && isNum(b[j])) {
				bNum.push_back(b[j]);
				j++;
			}
			j--;

			int aZero = 0, bZero = 0;
			string aa = "", bb = "";
			int aIdx = 0, bIdx = 0;
			while (aIdx < aNum.size() && aNum[aIdx++] == '0') aZero++;
			while (bIdx < bNum.size() && bNum[bIdx++] == '0') bZero++;
			aIdx--; bIdx--;

			while (aIdx < aNum.size()) aa += aNum[aIdx++];
			while (bIdx < bNum.size()) bb += bNum[bIdx++];

			if (aa.size() != bb.size()) return aa.size() < bb.size();

			for (int k = 0; k < aa.length(); k++) {
				if (aa[k] != bb[k]) return aa[k] < bb[k];
			}
			if (aZero != bZero) return aZero < bZero;
		}
		else if (a[i] == b[j]) continue;

		if(priority[a[i]] != priority[b[j]]) return priority[a[i]] < priority[b[j]];
	}
	return a.size() < b.size();
}

	int main() {
		for (int i = 48; i <= 57; i++) priority[i] = i;
		for (int i = 65, j = 65; i <= 90; i++, j += 2) priority[i] = j;
		for (int i = 97, j = 66; i <= 122; i++, j += 2) priority[i] = j;

		cin >> n;
		while (n--) {
			string s;
			cin >> s;
			arr.push_back(s);
		}

		sort(arr.begin(), arr.end(), compare);
		for (int i = 0; i < arr.size(); i++) cout << arr[i] << endl;
		return 0;
	}
