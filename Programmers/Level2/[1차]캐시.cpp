#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

queue<string> execute;

int solution(int cacheSize, vector<string> cities) {
	int time = 0;
	for (int i = 0; i < cities.size(); i++) {
		for (int j = 0; j < cities[i].size(); j++) {
			cities[i][j] = toupper(cities[i][j]);
		}
	}
	for (int i = 0; i < cities.size(); i++) {
		queue<string> ready;
			bool existed = false;
			while (!execute.empty()) {
				string city = execute.front();
				execute.pop();

				if (city.compare(cities[i])) ready.push(city);
				else existed = true;
			}
			time += existed ? 1 : 5;
			ready.push(cities[i]);

			while (ready.size() > cacheSize) ready.pop();
			while (!ready.empty()) {
				string tmp = ready.front();
				ready.pop();
				execute.push(tmp);
			}	
	}
	return time;
}
int main() {
	vector<string> v{ "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
	cout << solution(3,v) << endl;
	return 0;

}