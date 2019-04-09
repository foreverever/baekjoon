#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K, M;
vector<int> v[101001];
bool visit[101001];
int dist[101001];
queue<int> q;

int bfs(int start) {
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : v[cur]) {
			if (!visit[next]) {
				q.push(next);
				visit[next] = true;
				dist[next] = dist[cur] + 1;
			}
		}
	}
	if (N == 1) return 1;
	if (dist[N] == 0) return -1;
	return dist[N] / 2 + 1;
}

int main() {
	scanf("%d %d %d", &N, &K, &M);
	int x = 0;

	//하이퍼튜브도 하나의 노드로 간주하여 그래프 생성 (모든 노드간 연결 그래프를 만들 경우, 메모리 초과 및 시간 초과 발생)
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &x);
			v[N + i].push_back(x);
			v[x].push_back(N + i);
		}
	}
	
	printf("%d", bfs(1));
	return 0;
}