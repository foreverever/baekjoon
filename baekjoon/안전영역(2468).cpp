#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
using namespace std;

int arr[101][101];
bool visit[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N;
int range, height = 0;
queue<pair<int, int> > q;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (range < arr[i][j]) {
				range = arr[i][j];
			}
		}
	}
}

void bfs(int i, int j) {
	q.push({ i,j });
	visit[i][j] = true;
	while (!q.empty()) {
		for (int k = 0; k < 4; k++) {
			int ny = q.front().first + dy[k];
			int nx = q.front().second + dx[k];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (arr[ny][nx] > height && !visit[ny][nx]) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
		q.pop();
	}
}

int findAns() {
	int ans = -2e9;
	while (height < range) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] > height && !visit[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		ans = ans < cnt ? cnt : ans;
		memset(visit, false, sizeof(visit));
		height++;
	}
	return ans;
}

int main() {
	input();
	cout << findAns();
	return 0;
}