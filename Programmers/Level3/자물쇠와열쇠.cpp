#include <string>
#include <vector>
#include <iostream>
#define X first
#define Y second
using namespace std;

int n, m;
vector<pair<int, int>> notLock;
vector<pair<int, int>> locked;
vector<pair<int, int>> myKey;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	n = lock.size();
	m = key.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!lock[i][j]) locked.push_back(make_pair(i, j));
			else notLock.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < m; i++) 
		for (int j = 0; j < m; j++) 
			if (key[i][j]) myKey.push_back(make_pair(i, j));
	

	for (int rot = 0; rot < 4; rot++) {
	
		for (int i = 1 - m; i < n + m; i++) {
			for (int j = 1 - m; j < n + m; j++) {

				int open = 0;
				for (int k = 0; k < locked.size(); k++)
					for (int l = 0; l < myKey.size(); l++)
						if (myKey[l].X + i == locked[k].X && myKey[l].Y + j == locked[k].Y) open++;


				bool possible = true;
				for (int k = 0; k < notLock.size(); k++) {
					for (int l = 0; l < myKey.size(); l++) {
						if (myKey[l].X + i < 0 || myKey[l].X + i >= n || myKey[l].Y + j < 0 || myKey[l].Y + j >= n);
						else if (myKey[l].X + i == notLock[k].X && myKey[l].Y + j == notLock[k].Y) possible = false;
					}
				}

				if (open == locked.size() && possible) return true;
			}
		}
		for (int i = 0; i < myKey.size(); i++) {
			int tmp = myKey[i].X;
			myKey[i].X = myKey[i].Y;
			myKey[i].Y = m - tmp - 1;
		}
	}
	return false;
}
