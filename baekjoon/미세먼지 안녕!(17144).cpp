#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int R, C, T;
int house[51][51];
int tmp[51][51];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Pos {
	int y, x;
	Pos(int y, int x) : y(y), x(x) {};
};
vector<Pos> cleaner;

int calc() {
	int sum = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (house[i][j] == -1 || house[i][j] == 0) continue;
			sum += house[i][j];
		}
	}
	return sum;
}

void diffuse() {
	memset(tmp, 0, sizeof(tmp));
	for (Pos p : cleaner) tmp[p.y][p.x] = -1;

	//미세먼지 확산
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (house[i][j] != -1 && house[i][j] != 0) {	//미세먼지이면
				int cnt = 0;	//확산된 공간 수
				int mise = house[i][j] / 5;	//확산 될 미세먼지 양
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || nx < 0 || ny >= R || nx >= C || house[ny][nx] == -1) continue;
					cnt++;
					tmp[ny][nx] += mise;
				}
				tmp[i][j] += house[i][j] - (mise*cnt);
			}
		}
	}
	memcpy(house, tmp, sizeof(tmp));
}

void move(int cleanerY, int cleanerX, int * dir) {
	int y = cleanerY;
	int x = cleanerX + 1;

	for (int k = 0; k < 4; k++) {
		while (1) {
			int ny = y + dy[dir[k]];
			int nx = x + dx[dir[k]];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) break;
			if (ny == cleanerY && nx == cleanerX) break;
			house[ny][nx] = tmp[y][x];
			y = ny;
			x = nx;
		}
	}
	house[cleanerY][cleanerX + 1] = 0;
}

int findAns() {
	int reverseClockDir[4] = { 3,0,2,1 };	//반시계
	int clockDir[4] = { 3,1,2,0 };	//시계

	while (T--) {
		diffuse();
		move(cleaner[0].y, cleaner[0].x, reverseClockDir);
		move(cleaner[1].y, cleaner[1].x, clockDir);
	}
	return calc();
}

int main() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> house[i][j];
			if (house[i][j] == -1) {
				cleaner.push_back(Pos(i, j));
			}
		}
	}
	cout << findAns();
	return 0;
}