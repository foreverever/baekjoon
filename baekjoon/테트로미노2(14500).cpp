#include <iostream>

using namespace std;

int N, M, ans = -2e9;
int arr[501][501];
bool visit[501][501];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int y, int x, int cnt, int sum) {
	if (cnt == 4) {
		//max값 비교
		ans = ans < sum ? sum : ans;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (visit[ny][nx] == false) {
			visit[ny][nx] = true;
			dfs(ny, nx, cnt + 1, sum + arr[ny][nx]);
			visit[ny][nx] = false;
		}
	}
}

void findRemainder(int y, int x) {
	int sum = 0;
	//ㅗ
	if (y - 1 >= 0 && x + 2 < M) {
		sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 1];
		ans = ans < sum ? sum : ans;
	}
	//ㅏ
	if (y + 2 < N && x + 1 < M) {
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x + 1];
		ans = ans < sum ? sum : ans;
	}
	//ㅜ
	if (y + 1 < N && x + 2 < M) {
		sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1];
		ans = ans < sum ? sum : ans;
	}
	//ㅓ
	if (y + 2 < N && x - 1 >= 0) {
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x - 1];
		ans = ans < sum ? sum : ans;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = true;
			dfs(i, j, 1, arr[i][j]);
			visit[i][j] = false;
			findRemainder(i, j);	//ㅗ모양 탐색
		}
	}
	printf("%d", ans);
	return 0;
}