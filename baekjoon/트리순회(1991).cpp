#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int me, parent, left, right;
	Node(int me, int parent, int left, int right) {
		this->me = me;
		this->parent = parent;
		this->left = left;
		this->right = right;
	}
	Node() {}
};

Node nodes[91];
int n;
char parent, l, r;

void initTree() {
	for (int i = 'A'; i <= 'Z'; i++) {
		nodes[i] = Node(i, 0, 0, 0);
	}
}

void preOder(int node) {
	if (nodes[node].me!=0) printf("%c", nodes[node].me);
	if (nodes[node].left != 0) preOder(nodes[node].left);
	if (nodes[node].right != 0) preOder(nodes[node].right);
}

void inOder(int node) {
	if (nodes[node].left != 0) inOder(nodes[node].left);
	if (nodes[node].me != 0) printf("%c", nodes[node].me);
	if (nodes[node].right != 0) inOder(nodes[node].right);
}

void postOder(int node) {
	if (nodes[node].left != 0) postOder(nodes[node].left);
	if (nodes[node].right != 0) postOder(nodes[node].right);
	if (nodes[node].me != 0) printf("%c", nodes[node].me);
}

int main() {
	initTree();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> parent >> l >> r;
		if (l != '.') {
			nodes[l].parent = parent;
		}
		if (r != '.') {
			nodes[r].parent = parent;
		}
		nodes[parent].left = l;
		nodes[parent].right = r;
	}
	preOder('A'); printf("\n");
	inOder('A'); printf("\n");
	postOder('A'); printf("\n");
	return 0;
}