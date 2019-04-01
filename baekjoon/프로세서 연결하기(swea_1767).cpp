#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

struct Cell {
	int y, x;

	Cell(int y, int x) {
		this->y = y;
		this->x = x;
	}
	Cell() {}
};

int tc, N, cellSize, cnt, mx=-2e9, ans = 2e9;
int arr[13][13];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
Cell cells[12];

void dfs(int idx) {
	if (idx == cellSize) {
		//최대 프로세서 개수 세기
		if (mx < cnt) {
			mx = cnt;
			ans = 2e9;
			int sum = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (arr[i][j] == -1) sum++;
				}
			}
			ans = ans > sum ? sum : ans;
			return;
		}
		else if (mx == cnt) {
			int sum = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (arr[i][j] == -1) sum++;
				}
			}
			ans = ans > sum ? sum : ans;
			return;
		}
		return;
	}

	int backupCnt = 0;
	int backup[13][13];
	backupCnt = cnt;
	memcpy(backup, arr, sizeof(arr));

	for (int k = 0; k < 4; k++) {
		int ny = cells[idx].y;
		int nx = cells[idx].x;
		bool isPossible = false;
		//전력 연결 유무 판단
		while (1) {
			ny += dy[k];
			nx += dx[k];
			if (arr[ny][nx] == -1 || arr[ny][nx] == 1) break;
			if (ny == 0 || nx == 0 || ny == N - 1 || nx == N - 1) {
				isPossible = true;
				break;
			}
		}
		//연결가능 하면 전선 설치
		if (isPossible) {
			ny = cells[idx].y;
			nx = cells[idx].x;
			while (1) {
				if (ny == 0 || nx == 0 || ny == N - 1 || nx == N - 1) break;
				ny += dy[k];
				nx += dx[k];
				arr[ny][nx] = -1;
			}
			cnt++;
		}
		dfs(idx + 1);
		memcpy(arr, backup, sizeof(arr));
		cnt = backupCnt;
	}
}

int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
				if (i == 0 || j == 0 || i == N - 1 || j == N - 1) continue;
				if (arr[i][j] == 1) {
					cells[cellSize] = Cell(i, j);
					cellSize++;
				}
			}
		}
		dfs(0);
		printf("#%d %d\n", t, ans);
		cellSize = 0;
		ans = 2e9;
		mx = -2e9;
		cnt = 0;
	}
	return 0;
}