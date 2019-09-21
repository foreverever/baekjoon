#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define DIV 1000000007 
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int land[102][102], number[102][102];
bool used[102][102];

struct Pos {
	int y, x;

	Pos(int y, int x) {
		this->y = y;
		this->x = x;
	}
};

int bfs(int y, int x, int m, int n) {
	queue<Pos> q;
	q.push(Pos(y, x));
	number[1][1] = 1;
	used[1][1] = true;

	while (!q.empty()) {
		Pos cur = q.front(); q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];
			if (ny<1 || nx <1 || ny > n || nx >m) continue;
			if (land[ny][nx] != 1 && !used[ny][nx]) {
				q.push(Pos(ny, nx));
				used[ny][nx] = true;
				if (ny - 1 >= 1 && land[ny - 1][nx] != 1) number[ny][nx] += number[ny - 1][nx] % DIV;
				if (nx - 1 >= 1 && land[ny][nx - 1] != 1) number[ny][nx] += number[ny][nx - 1] % DIV;
				//number[ny][nx] = number[cur.y][cur.x];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << number[i][j];
		}
		cout << '\n';
	}

	return number[n][m];
}

int solution(int m, int n, vector<vector<int>> puddles) {
	for (int i = 0; i < puddles.size(); i++) {
		land[puddles[i][1]][puddles[i][0]] = 1;
	}
	return bfs(1, 1, m, n);
}