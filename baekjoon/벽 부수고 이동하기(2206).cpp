#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

struct Node {
	int y, x, breaked;
};

int N, M, ans;
int arr[MAX][MAX], dist[MAX][MAX][2];	//벽을  안부순(0), 부순(1) 2가지 상태를 각각 가져야함
bool visit[MAX][MAX][2];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
Node start;
queue<Node> q;

void bfs() {
	q.push(start);
	dist[start.y][start.x][start.breaked] = 1;
	visit[start.y][start.x][start.breaked] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			if (visit[ny][nx][cur.breaked] == false) {
				if (arr[ny][nx] == 0) {	//다음 노드에 벽이 없을 경우
					q.push(Node{ ny,nx,cur.breaked });
					visit[ny][nx][cur.breaked] = true;
					dist[ny][nx][cur.breaked] = dist[cur.y][cur.x][cur.breaked] + 1;
				}
				else {	//다음 노드에 벽이 있을 경우
					if (cur.breaked == 0) {	//이전에 벽을 부수지 않은 경우
						q.push(Node{ ny,nx,1 });
						visit[ny][nx][cur.breaked] = true;
						dist[ny][nx][1] = dist[cur.y][cur.x][cur.breaked] + 1;
					}
				}
			}
		}
	}
}


void findAns() {
	bfs();
	int noB = dist[N - 1][M - 1][0];
	int b = dist[N - 1][M - 1][1];
	if (noB == 0 || b == 0) {
		ans = max(noB, b);
	}
	else ans = min(noB, b);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	findAns();
	if (ans) printf("%d", ans);
	else printf("%d", -1);
	return 0;
}