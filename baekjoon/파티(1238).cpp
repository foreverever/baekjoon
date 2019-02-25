#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;
int N, M, X, from, to, weight;
int dist[MAX], total[MAX];

struct Node {
	int me, weight;
	Node(int me, int weight) {
		this->me = me;
		this->weight = weight;
	}
	Node() {}
};

struct cmp {
	bool operator()(const Node &n1, const Node &n2) {
		return n1.weight > n2.weight;
	}
};

vector<vector<Node> > nodes;
vector<vector<Node> > reverseNodes;
priority_queue<Node, vector<Node>, cmp> q;

void findAns(vector<vector<Node> > nodes) {
	q.push(Node(X,0));
	dist[X] = 0;

	while (!q.empty()) {
		Node cur = q.top();
		q.pop();
		for (Node next : nodes[cur.me]) {
			if (dist[next.me] > dist[cur.me] + next.weight) {
				dist[next.me] = dist[cur.me] + next.weight;
				next.weight = dist[next.me];
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		total[i] += dist[i];
	}
}

bool desc(int a, int b) {
	return a > b;
}

void initDist() {
	for (int i = 1; i <= N; i++) {
		dist[i] = 2e7;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &X);
	nodes.resize(N + 1);
	reverseNodes.resize(N+1);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		nodes[from].push_back(Node(to, weight));
		reverseNodes[to].push_back(Node(from, weight));
	}
	initDist();
	findAns(nodes);
	initDist();
	findAns(reverseNodes);
	sort(total + 1, total + N + 1, desc);
	printf("%d", total[1]);
	return 0;
}