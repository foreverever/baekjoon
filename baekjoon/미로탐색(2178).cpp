#include <iostream>
#include <queue>
#include <utility>
#define MAX 101

using namespace std;

int map[MAX][MAX];	//맵
int distMap[MAX][MAX];	//가중치 배열
bool checkMap[MAX][MAX];	//방문 체크 배열(false로 초기화)
int n, m;	//배열 범위	(n:세로, m:가로)
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

//범위체크 함수
bool isNotInsideMap(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m) {
		return true;
	}
	return false;
}

//BFS함수
void bfs(int i, int j) {
	queue <pair<int, int> > q;
	q.push(make_pair(i, j));
	checkMap[i][j] = true;	//방문 표시
	distMap[i][j] += 1;
	//queue가 비어있을 때 까지 탐색
	while (!q.empty()) {
		//현재위치에서 상하좌우 탐색
		for (int k = 0; k < 4; k++) {
			int y = q.front().first + dy[k];
			int x = q.front().second + dx[k];
			if (isNotInsideMap(y, x)) continue;
			if (map[y][x] == 1 && checkMap[y][x] == false) {
				q.push(make_pair(y, x));
				checkMap[y][x] = true;
				distMap[y][x] = distMap[q.front().first][q.front().second] + 1;
			}
		}
		q.pop();
	}
}

//미로탐색 출발점에서 시작
int start() {
	if (map[0][0] == 1 && checkMap[0][0] == false) {
		bfs(0, 0);
		return distMap[n - 1][m - 1];
	}
}

int main() {
	cin >> n >> m;
	//맵 정보 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int ans = start();
	cout << ans;
	return 0;
}
