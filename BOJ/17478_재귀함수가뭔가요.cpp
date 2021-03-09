#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

string a = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
string b = "\"재귀함수가 뭔가요?\"";
string c = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
string c2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
string c3 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
string d = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
string e = "라고 답변하였지.";

void rec(int cur, int n, int cnt) {
	if (cur == n) {
		for (int i = 0; i < cnt; i++) cout << '_';
		cout << b << endl;
		for (int i = 0; i < cnt; i++) cout << '_';
		cout << d << endl;
		for (int i = 0; i < cnt; i++) cout << '_';
		cout << e << endl;
		return;
	};
	for (int i = 0; i < cnt; i++) cout << '_';
	cout << b << endl;
	for (int i = 0; i < cnt; i++) cout << '_';
	cout << c << endl;
	for (int i = 0; i < cnt; i++) cout << '_';
	cout << c2 << endl;
	for (int i = 0; i < cnt; i++) cout << '_';
	cout << c3 << endl;

	rec(cur + 1, n, cnt + 4);

	for (int i = 0; i < cnt; i++) cout << '_';
	cout << e << endl;
}

int main() {
	int n;
	cin >> n;

	cout << a << endl;

	rec(0, n, 0);
	return 0;
}

