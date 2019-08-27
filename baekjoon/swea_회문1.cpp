#include <iostream>
#include <string>
#define MAX_SIZE 8
using namespace std;

char board[8][8];
int N, ans;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void mulDir() {
	for (int i = 0; i < 4; i++) {
		dy[i] *= (N - 1);
		dx[i] *= (N - 1);
	}
}

void initDir() {
	dy[0] = -1, dy[1] = 1, dy[2] = 0, dy[3] = 0;
	dx[0] = 0, dx[1] = 0, dx[2] = -1, dx[3] = 1;
}

void input() {
	scanf("%d", &N);
	mulDir();
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
}

int count(int y, int x) {
	int my = 0, mx = 0, cnt = 0;

	for (int k = 0; k < 4; k++) {
		my = dy[k] + y;
		mx = dx[k] + x;
		if (my < 0 || mx < 0 || my >= 8 || mx >= 8) continue;
		string a = "", b = "";

		if (my > y) {
			for (int i = y; i <= my; i++) {
				a += board[i][x];
				b += board[y + my - i][x];
			}
		}
		else if (my < y) {
			for (int i = my; i <= y; i++) {
				a += board[i][x];
				b += board[y + my - i][x];
			}
		}
		else if (mx > x) {
			for (int i = x; i <= mx; i++) {
				a += board[y][i];
				b += board[y][x + mx - i];
			}
		}
		else {
			for (int i = mx; i <= x; i++) {
				a += board[y][i];
				b += board[y][x + mx - i];
			}
		}
		if (a == b) cnt++;
	}
	return cnt;
}

int findAns() {
	int cnt = 0;
	input();

	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cnt += count(i, j);
		}
	}
	initDir();
	return cnt/2;
}

int main() {
	for (int t = 1; t <= 10; t++) {
		cout << "#" << t << ' ' << findAns() << '\n';
		ans = 0;
	}
	return 0;
}