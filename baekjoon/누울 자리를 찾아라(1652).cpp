#include <iostream>
#include <utility>
#define RIGHT 0
#define DOWN 1
using namespace std;

int N;
char arr[101][101];
bool rightDir[101][101], downDir[101][101];
pair<int, int> ans;

void check(int y, int x, int dir) {
	int len = 0;

	if (dir == RIGHT) {
		while (arr[y][x] != 'X' && x < N) {
			rightDir[y][x] = true;
			len++;
			x++;
		}
		if (len >= 2) ans.first++;
	}
	else if (dir == DOWN) {
		while (arr[y][x] != 'X' && y < N) {
			downDir[y][x] = true;
			len++;
			y++;
		}
		if (len >= 2) ans.second++;
	}
}

void findAns() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (rightDir[i][j] == false) check(i, j, RIGHT);
			if (downDir[i][j] == false) check(i, j, DOWN);
		}
	}
}

int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}

	findAns();
	printf("%d %d", ans.first, ans.second);
	return 0;
}