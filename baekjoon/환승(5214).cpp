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

	//������Ʃ�굵 �ϳ��� ���� �����Ͽ� �׷��� ���� (��� ��尣 ���� �׷����� ���� ���, �޸� �ʰ� �� �ð� �ʰ� �߻�)
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