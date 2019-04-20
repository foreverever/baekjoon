#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int me, dist;

	Node(int n, int dist) {
		this->me = n;
		this->dist = dist;
	}
	
	Node() {};
};

struct cmp {
	bool operator()(Node &first, Node &second) {
		return first.dist > second.dist;
	}
};

int dist[51];
vector<Node> nodes[51];
priority_queue<Node, vector<Node>, cmp> q;

void initDist(int N) {
	for (int i = 1; i <= N; i++) {
		dist[i] = 2e9;
	}
}

void bfs(int N) {
	q.push(Node(1, 0));
	dist[1] = 0;

	while (!q.empty()) {
		Node cur = q.top();
		q.pop();
		for (Node next : nodes[cur.me]) {
			if (dist[next.me] > dist[cur.me] + next.dist) {
				dist[next.me] = dist[cur.me] + next.dist;
				next.dist = dist[next.me];
				q.push(next);
			}
		}
	}
}

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	initDist(N);
	
	for (int i = 0; i < road.size(); i++) {
		nodes[road[i][0]].push_back(Node(road[i][1], road[i][2]));
		nodes[road[i][1]].push_back(Node(road[i][0], road[i][2]));
	}
	bfs(N);

	for (int i = 1; i <= N; i++) {
		if (dist[i] <= K) answer++;
	}
	return answer;
}

int main() {

}