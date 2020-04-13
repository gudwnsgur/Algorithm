#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define NodeMAX 10001
using namespace std;

vector<int> pre;
vector<int> post;

class Node {
	friend class Tree;
private:
	int name;
	int value;
	Node* left;
	Node* right;
public:
	Node() {};
};

class Tree {
	friend Node;
private:
	Node* root;
public:
	Tree() { root = NULL; };
	Node* findRoot() { return root; };
	void insert(int& name, int& value);
	void preorder(Node* node);
	void postorder(Node* node);
};


void Tree::insert(int& name, int& value) {
	Node* p = root;
	Node* q = NULL;

	while (p) {
		q = p;
		if (value < p->value) p = p->left;
		else p = p->right;
	}
	p = new Node;
	p->left = p->right = NULL;
	p->name = name; p->value = value;

	if (!root) root = p;
	else if (value < q->value) q->left = p;
	else q->right = p;
}


void Tree::preorder(Node* node) {
	if (node) {
		pre.push_back(node->name);
		preorder(node->left);
		preorder(node->right);
	}

}

void Tree::postorder(Node* node) {
	if (node) {
		postorder(node->left);
		postorder(node->right);
		post.push_back(node->name);
	}

}

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.second.second == b.second.second) {
		return 	a.second.first < b.second.first;
	}	return a.second.second > b.second.second;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	vector<vector<int>> answer;

	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < nodeinfo.size(); i++) {
		v.push_back(make_pair(i + 1, make_pair(nodeinfo[i][0], nodeinfo[i][1])));
	}
	sort(v.begin(), v.end(), cmp);


	Tree T;
	for (int i = 0; i < v.size(); i++) {
		T.insert(v[i].first, v[i].second.first);
	}

	T.preorder(T.findRoot());
	T.postorder(T.findRoot());

	answer.push_back(pre);
	answer.push_back(post);

	return answer;
}

int main() {
	vector<vector<int>> answer = solution({ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });
	return 0;
}