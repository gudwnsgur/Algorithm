	#include <iostream>
    #include <string>
	#include <vector>
	#include <algorithm>
	using namespace std;

	vector<int> solution(vector<int> answers) {
		vector<int> answer;
		int* count = new int[3];
		count[0] = count[1] = count[2] = 0;

		vector<int> aAns, bAns, cAns;
		for (int i = 1; i <= answers.size(); i ++) 
		{
			if (i % 5 == 0) aAns.push_back(5);
			else aAns.push_back(i % 5);
			// 1 2 3 4 5 1 2 3 4 5

			if (i%2 != 0) bAns.push_back(2);
			else if ( i % 8 == 2) bAns.push_back(1);
			else if ( i % 8 == 4) bAns.push_back(3);
			else if ( i % 8 == 6) bAns.push_back(4);
			else if ( i % 8 == 0) bAns.push_back(5);
			// 2 1 2 3 2 4 2 5 


			if ( i % 10 == 1 || i % 10 == 2) cAns.push_back(3);
			else if ( i % 10 == 3 || i % 10 == 4) cAns.push_back(1);
			else if ( i % 10 == 5 || i % 10 == 6) cAns.push_back(2);
			else if ( i % 10 == 7 || i % 10 == 8) cAns.push_back(4);
			else cAns.push_back(5);
			// 33 11 22 44 55
		}

		for (int i = 0; i < answers.size(); i++) {
			if (aAns[i] == answers[i]) { count[0]++; }
			if (bAns[i] == answers[i]) { count[1]++; }
			if (cAns[i] == answers[i]) { count[2]++; }
		}
		int maxProb = max(count[0], max(count[1], count[2]));
		for (int i = 0; i < 3; i++) {
			if (maxProb == count[i]) answer.push_back(i + 1);
		}
		return answer;
	}
