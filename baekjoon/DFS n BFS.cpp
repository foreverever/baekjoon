#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M, V;
int arr[1001][1001];
bool isVisit[1001];

void input() {
	cin >> N >> M >> V;
	int y, x;

	for (int i = 0; i < M; i++) {
		cin >> y >> x;
		arr[y][x] = arr[x][y] = 1;
	}
}

void dfs(int cur) {
	cout << cur << ' ';
	isVisit[cur] = true;

	for (int i = 1; i <= N; i++) {
		if (arr[cur][i] == 1 && !isVisit[i]) dfs(i);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	isVisit[start] = true;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << ' ';

		for (int i = 1; i <= N; i++) {
			if (arr[cur][i] == 1 && !isVisit[i]) {
				q.push(i);
				isVisit[i] = true;
			}
		}
	}
}

void findAns() {
	dfs(V);
	cout << '\n';
	memset(isVisit, false, sizeof(isVisit));
	bfs(V);
}

int main() {
	ios_base::sync_with_stdio(false);
	input();
	findAns();
	return 0;
}