#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
	char left;
	char right;
};

vector<Node> tree(100);


void preOrder(char root) {
	if (root == '.') return;
	cout << root;
	preOrder(tree[root].left);
	preOrder(tree[root].right);
}
void inOrder(char root)
{
	if (root == '.') return;
	inOrder(tree[root].left);
	cout << root;
	inOrder(tree[root].right);
}

void postOrder(char root)
{
	if (root == '.') return;
	postOrder(tree[root].left);
	postOrder(tree[root].right);
	cout << root;
}



int main() {

	int n;
	cin >> n;
	char a, b, c;
	while (n--) {
		cin >> a >> b >> c;
		tree[a].left = b;
		tree[a].right = c;
	}

	preOrder('A');
	cout << endl;
	inOrder('A');
	cout << endl;
	postOrder('A');
	cout << endl;
	return 0;
}
