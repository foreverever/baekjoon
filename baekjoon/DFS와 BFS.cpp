#include <iostream>
#include <string.h>
#include <queue>
#define MAX 1001
using namespace std;

int N, M, V, from, to;
int arr[MAX][MAX];
bool visited[MAX];
queue<int> q;

void dfs(int cur) {
	visited[cur] = true;
	printf("%d ", cur);
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false && arr[cur][i] == 1) {
			dfs(i);
		}
	}
}

void bfs(int cur) {
	visited[cur] = true;
	q.push(cur);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = 1; i <= N; i++) {
			if (visited[i] == false && arr[now][i] == 1) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &from, &to);
		arr[from][to] = arr[to][from] = 1;
	}
	dfs(V);
	printf("\n");
	memset(visited, false, sizeof(visited));
	bfs(V);
	return 0;
}