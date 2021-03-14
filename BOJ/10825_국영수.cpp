#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#define endl '\n'
using namespace std;

struct Student{
	string name;
	int kor, eng, mat;
};

bool compare(Student a, Student b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.mat == b.mat) return a.name < b.name;
			return  a.mat > b.mat;
		}
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main() {
	int n;
	cin >> n;
	vector<Student> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].mat;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) cout << v[i].name << endl;
	return 0;
}

