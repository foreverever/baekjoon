#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int N, M, start, dest;
int from, to, cost;
int dist[MAX];

struct  Node {
	int number, cost;
	Node(int to, int cost) {
		this->number = to;
		this->cost = cost;
	}
	Node() {}
};

struct cmp {
	bool operator()(const Node &n1, const Node &n2) {
		return n1.cost > n2.cost;
	}
};

vector<vector<Node> > v;
priority_queue<Node, vector<Node>, cmp> q;

void findAns() {
	q.push(Node(start, 0));
	dist[start] = 0;

	while (!q.empty()) {
		Node cur = q.top();
		q.pop();
		for (Node next : v[cur.number]) {
			if (dist[next.number] > next.cost + dist[cur.number]) {
				dist[next.number] = next.cost + dist[cur.number];
				next.cost = dist[next.number];
				q.push(next);
			}
		}
	}
}

void initDist() {
	for (int i = 1; i <= N; i++) {
		dist[i] = 2e9;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	v.resize(N + 1);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back(Node(to, cost));
	}
	scanf("%d %d", &start, &dest);
	initDist();
	findAns();
	printf("%d", dist[dest]);
	return 0;
}