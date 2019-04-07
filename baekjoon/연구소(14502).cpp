#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct Pos {
	int y, x;
	Pos(int y, int x) {
		this->y = y;
		this->x = x;
	}
	Pos() {}
};

int N, M, poseSize, ans = -2e9, wall;
int arr[9][9], visit[9][9];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

Pos poses[65];
bool used[65];
queue<Pos> q;

void bfs(Pos p) {
	visit[p.y][p.x] = true;
	q.push(p);

	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (arr[ny][nx] == 0 && visit[ny][nx] == false) {
				visit[ny][nx] = true;
				wall++;
				q.push(Pos(ny, nx));
				if (poseSize - wall < ans) return;	//���� ans�� wall �������� ũ��, �� �̻� Ž���� �ʿ� ����.
			}
		}
	}
}

void dfs(int cnt, int idx) {
	if (cnt == 3) {
		//bfs����
		wall = 3;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 2 && visit[i][j] == false) {
					bfs(Pos(i, j));
				}
			}
		}
		//ans �ִ밪 ��
		int diff = poseSize - wall;
		ans = ans < diff ? diff : ans;

		//q ���
		while (!q.empty()) q.pop();

		//visit �ʱ�ȭ
		memset(visit, false, sizeof(visit));
		return;
	}

	for (int cur = idx; cur < poseSize; cur++) {
		if (!used[cur]) {
			used[cur] = true;
			arr[poses[cur].y][poses[cur].x] = 1;
			dfs(cnt + 1, cur + 1);
			used[cur] = false;
			arr[poses[cur].y][poses[cur].x] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0) {
				poses[poseSize++] = Pos(i, j);
			}
		}
	}

	dfs(0, 0);
	printf("%d", ans);
	return 0;
}