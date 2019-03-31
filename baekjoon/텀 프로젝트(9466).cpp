#include <iostream>

using namespace std;

struct Node {
	int next;
	bool visited = false, isFinished = false;

	Node(int next) {
		this->next = next;
	}
	
	Node() {}
};

int tc, N, cnt;
Node nodes[100001];

void dfs(int cur) {
	nodes[cur].visited = true;
	int next = nodes[cur].next;
	if (!nodes[next].visited) dfs(next);
	else {
		if (!nodes[next].isFinished) {
			nodes[next].isFinished = true;
			cnt++;
			for (int k = next; k != cur; k = nodes[k].next) {
				cnt++;
			}
		}
	}
	nodes[cur].isFinished = true;
}

int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &N);
		int x;
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &x);
			nodes[i] = Node(x);
		}
		for (int i = 1; i <= N; i++) {
			if (!nodes[i].visited) {
				dfs(i);
			}
		}
		printf("%d\n", N - cnt);
	}
	return 0;
}