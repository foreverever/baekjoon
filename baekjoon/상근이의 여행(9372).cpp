#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int tc, N, M;
int city[1001][1001];
bool visit[1001];

int bfs(int start) {
	queue<int> q;
	int ans = 0;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (city[cur][i] == 1 && visit[i] == false) {
				q.push(i);
				visit[i] = true;
				ans++;
			}
		}
	}
	return ans;
}

void init() {
	memset(city, 0, sizeof(city));
	memset(visit, false, sizeof(visit));
}

int main() {
	scanf("%d", &tc);
	int x, y;

	for (int t = 1; t <= tc; t++) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &x, &y);
			city[x][y] = city[y][x] = 1;
		}
		printf("%d\n", bfs(x));
		init();
	}
	return 0;
}