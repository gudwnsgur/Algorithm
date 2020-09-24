#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
map<string, vector<pair<int, int>>> m; // genres -> { plays, index}
map<string, int> sum; // genres -> sum
vector<string> g; // genres

bool compare1(string a, string b) {
	return sum.find(a)->second > sum.find(b)->second;
}
bool compare2(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	// m.find("f") == m.end() : not found
	for (int i = 0, j=0; i < genres.size(); i++) {
		if (m.find(genres[i]) == m.end()) {
			g.push_back(genres[i]);
			vector<pair<int,int>> tmp;
			tmp.push_back(make_pair(plays[i],i));
			m.insert(make_pair(genres[i], tmp));
			sum.insert(make_pair(genres[i], plays[i]));
		}
		else {
			m.find(genres[i])->second.push_back(make_pair(plays[i],i));
			sum.find(genres[i])->second += plays[i];
		}
	}

	sort(g.begin(), g.end(), compare1);

	for (int i = 0; i < g.size(); i++) {
		if (m.find(g[i])->second.size() == 1) answer.push_back(m.find(g[i])->second[0].second);
		else {
			sort(m.find(g[i])->second.begin(), m.find(g[i])->second.end(), compare2);
			answer.push_back(m.find(g[i])->second[0].second);
			answer.push_back(m.find(g[i])->second[1].second);
		}
	}

	return answer;
}