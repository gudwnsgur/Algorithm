#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;


char op[6][3] = { {'+', '-', '*',}, {'+', '*', '-'},
				  {'-', '+', '*'}, {'-', '*', '+'},
				  {'*', '+', '-'}, {'*', '-', '+'}};
vector<char> inputOp, op1, op2;
vector<ll> inputNum, tmp1, tmp2;


void calculation(char op) {
	tmp2.push_back(tmp1[0]);

	for (int i = 0; i < tmp1.size()-1; i++) {
		if (op != op1[i]) {
			tmp2.push_back(tmp1[i+1]);
			op2.push_back(op1[i]);
		}
		else {
			if (op == '+') tmp2.back() += tmp1[i + 1];
			else if (op == '-') tmp2.back() -= tmp1[i + 1];
			else tmp2.back() *= tmp1[i + 1];
		}
	}
	tmp1 = tmp2;
	op1 = op2;
	tmp2.clear();
	op2.clear();
	return;
}

long long solution(string expression) {
	ll answer = 0;

	string num = "";
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] >= '0' && expression[i] <= '9') num.push_back(expression[i]);
		else {
			inputOp.push_back(expression[i]);
			inputNum.push_back(stoi(num));
			num = "";
		}
	}
	inputNum.push_back(stoi(num));

	for (int i = 0; i < 6; i++) {
		tmp1 = inputNum;
		op1 = inputOp;

		for (int j = 0; j < 3; j++) 
			calculation(op[i][j]);
		answer = max(answer, abs(tmp1[0]));
	}
	return answer;
}
