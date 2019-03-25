#include <iostream>
#include <memory.h>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

struct CCTV {
	int y, x, type;

	CCTV(int y, int x, int type) {
		this->y = y;
		this->x = x;
		this->type = type;
	}
	CCTV() {}
};

CCTV cctves[8];
bool used[8];
int direction[6] = { 0,4,2,4,4,1 };
int N, M, cctvSize, ans = 2e9;
int arr[9][9];

void copyArr(int to[9][9], int from[9][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			to[i][j] = from[i][j];
		}
	}
}

//cctv 범위 갱신 (한 방향에 대해)
void update(CCTV cur, int dir) {
	if (dir == UP) {
		for (int i = 1; i < N; i++) {
			if (cur.y - i < 0 || arr[cur.y - i][cur.x] == 6) return;	//범위초과 or 벽을 만날경우 리턴
			arr[cur.y - i][cur.x] = -1;
		}
	}
	if (dir == RIGHT) {
		for (int i = 1; i < M; i++) {
			if (cur.x + i >= M || arr[cur.y][cur.x + i] == 6) return;
			arr[cur.y][cur.x + i] = -1;
		}
	}
	if (dir == DOWN) {
		for (int i = 1; i < N; i++) {
			if (cur.y + i >= N || arr[cur.y + i][cur.x] == 6) return;
			arr[cur.y + i][cur.x] = -1;
		}
	}
	if (dir == LEFT) {
		for (int i = 1; i < M; i++) {
			if (cur.x - i < 0 || arr[cur.y][cur.x - i] == 6) return;
			arr[cur.y][cur.x - i] = -1;
		}
	}
}

void dfs(int cnt, int idx) {
	if (cnt == cctvSize) {
		//0개수 세기
		int sum = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0) {
					sum++;
				}
			}
		}
		ans = ans > sum ? sum : ans;
	}
	for (int i = idx; i < cctvSize; i++) {
		if (used[i] == false) {
			int backup[9][9];
			memcpy(backup, arr, sizeof(arr));
			used[i] = true;
			CCTV cur = cctves[i];	//현재 선택된 cctv에 대해
			for (int dir = 0; dir < direction[cur.type]; dir++) {	//현재 cctv의 회전 경우의 수에 대해 맵 갱신
				if (cur.type == 1) {
					update(cur, dir);
				}
				else if (cur.type == 2) {
					update(cur, dir);
					update(cur, (dir + 2) % 4);
				}
				else if (cur.type == 3) {
					update(cur, dir);
					update(cur, (dir + 1) % 4);
				}
				else if (cur.type == 4) {
					update(cur, dir);
					update(cur, (dir + 1) % 4);
					update(cur, (dir + 2) % 4);
				}
				else if (cur.type == 5) {
					update(cur, dir);
					update(cur, (dir + 1) % 4);
					update(cur, (dir + 2) % 4);
					update(cur, (dir + 3) % 4);
				}
				dfs(cnt + 1, i + 1);
				used[i] = false;
				memcpy(arr, backup, sizeof(arr));
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				cctves[cctvSize] = CCTV(i, j, arr[i][j]);
				cctvSize++;
			}
		}
	}
	dfs(0, 0);
	printf("%d", ans);
	return 0;
}