#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

struct Pos {
	int y, x, area;
	bool valid = false;

	Pos(int y, int x, int area) {
		this->y = y;
		this->x = x;
		this->area = area;
	}
	Pos() {}
};

Pos poses[10001];
bool used[10001];
bool visit[101][101];
int arr[101][101];
int N, posSize, ans = 2e9;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int cnt, int idx, int h, int w, int before) {
	if (cnt == 2) {
		int sum = h + w - 1;
		ans = ans > sum ? sum : ans;
		return;
	}
	for (int i = idx; i < posSize; i++) {
		if (used[i] == false && poses[i].area != before) {
			used[i] = true;
			dfs(cnt + 1, i + 1, abs(h - poses[i].y), abs(w - poses[i].x), poses[i].area);
			used[i] = false;
		}
	}
}

void bfs(Pos p , int num) {
	queue<Pos> q;
	q.push(p);
	visit[p.y][p.x] = true;

	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visit[ny][nx] == false && arr[ny][nx] == 1) {
				visit[ny][nx] = true;
				q.push(Pos(ny,nx,num));
			}
			else if (arr[ny][nx] == 0 && cur.valid == false) {
				cur.valid = true;
				poses[posSize++] = cur;
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && arr[i][j] == 1) {
				bfs(Pos(i, j, num), num);
				num++;
			}
		}
	}
	dfs(0, 0, 0, 0, 0);
	printf("%d", ans);
	return 0;
}