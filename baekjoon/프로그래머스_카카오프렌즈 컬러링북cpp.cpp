#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
bool used[102][102];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Result {
	int area = 0;
	int max = -2e9;

	void init(int area, int max) {
		this->area = area;
		this->max = max;
	}
};

struct Pos {
	int y, x;
	Pos(int y, int x) {
		this->y = y;
		this->x = x;
	}
};

Result result;

void bfs(int m, int n, vector<vector<int>> &picture, int y, int x) {
	queue<Pos> q;
	q.push(Pos(y, x));
	used[y][x] = true;
	
	int cnt = 1;
	while (!q.empty()) {
		Pos cur = q.front(); q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (!used[ny][nx] && picture[ny][nx] == picture[y][x]) {
				used[ny][nx] = true;
				q.push(Pos(ny, nx));
				cnt++;
			}
		}
	}
	result.max = result.max < cnt ? cnt : result.max;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	memset(used, false, sizeof(used));
	result.init(0, -2e9);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!used[i][j] && picture[i][j] != 0) {
				result.area++;
				bfs(m, n, picture, i, j);
			}
		}
	}

	vector<int> answer(2);
	answer[0] = result.area;
	answer[1] = result.max;
	return answer;
}