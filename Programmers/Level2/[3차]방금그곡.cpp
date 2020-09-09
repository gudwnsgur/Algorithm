#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<string, string>> music;
vector<pair<string , pair<int, int>>> info;
string newM = "";
// A#, C#, D#, F#, G# => K, M, N, P, Q

bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) return a.second.second < b.second.second;
	return a.second.first > b.second.first;
}


string solution(string m, vector<string> musicinfos) {
	string answer = "";
	
	for (int i = 0; i < m.size()-1; i++) {
		if (m[i + 1] != '#')  newM += m[i];
		else {
			newM += m[i] + 10;
			i++;
		}
	}
	if (m[m.size() - 1] != '#') newM += m[m.size() - 1];
	


	for (int i = 0; i < musicinfos.size(); i++) {
		int musicLength;
		string str = musicinfos[i];
		musicLength = 60 * (stoi(str.substr(6, 2)) - stoi(str.substr(0, 2)))
						+ (stoi(str.substr(9, 2)) - stoi(str.substr(3, 2)));

		

		string name = "", flow="", tmp="";
		int index = 12;
		for (; str[index] != ','; index++) name += str[index];
		index++;
		for (; index < str.size(); index++)  flow += str[index];

		for (int j = 0; j < flow.size() - 1; j++) {
			if (flow[j + 1] != '#')  tmp += flow[j];
			else {
				tmp += flow[j] + 10;
				j++;
			}
		} 
		if (flow[flow.size() - 1] != '#') tmp += flow[flow.size() - 1];

		flow = "";

		// musicLength == 14, tmp.size() == 8
		for (int j = 0, k=0; j < musicLength; j++, k%=tmp.size()) {
			flow += tmp[k++];
		}

		cout << name << ' ' << flow << ' ' << musicLength << endl;
		music.push_back(make_pair(name, flow));
	}
	bool existed = false;
	for (int i = 0; i < music.size(); i++) {
		if (music[i].second.find(newM) != std::string::npos) {
			info.push_back(make_pair(music[i].first, make_pair(music[i].second.size(), i)));
			existed = true;
		}
	}
	if(!existed) return "(None)";


	sort(info.begin(), info.end(), compare);
	return info[0].first;
}