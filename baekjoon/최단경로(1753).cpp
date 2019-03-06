#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E, K;
int dist[20001];	//index번호 노드까지 최단 거리

struct node
{
	int number, weight;	//목표정점, 해당 정점까지 최단거리

	node(int to, int weight) {
		this->number = to;
		this->weight = weight;
	}
	//bool operator < (const node a)const {
	//	return weight > a.weight;
	//}
};

struct cmp {
	bool operator()(node t, node u) {
		return t.weight > u.weight;
	}
};

void initDist() {
	for (int i = 1; i <= V; i++) {
		dist[i] = 2e7;
	}
}

vector<vector<node> > v;

void input() {
	cin >> V >> E >> K;
	v.resize(V + 1);
	int from, to, weight;
	for (int i = 0; i < E; i++) {
		cin >> from >> to >> weight;
		v[from].push_back(node(to, weight));
	}
	initDist();
}

void findAns() {
	priority_queue<node, vector<node>, cmp> pq;
	pq.push(node(K, 0));
	dist[K] = 0;

	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();
		for (node next : v[cur.number]) {
			if (dist[next.number] > next.weight + dist[cur.number]) {
				dist[next.number] = next.weight + dist[cur.number];
				next.weight = dist[next.number];
				pq.push(next);
			}
		}
	}
}

int main() {
	input();
	findAns();
	for (int i = 1; i <= V; i++) {
		if (dist[i] == 2e7) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;
}