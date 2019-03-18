#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct Pos {
	int y, x, dist = 2e9;
	Pos(int y, int x) {
		this->y = y;
		this->x = x;
	}
	Pos() {}
};

int N, M, storeSize, homeSize, ans = 2e9;
int arr[51][51];
bool used[14];
Pos store[14], home[101];

void copyTemp(Pos to[101] , Pos from[101]) {
	for (int i = 0; i < homeSize; i++) {
		to[i] = from[i];
	}
}

void dfs(int cnt, int idx) {
	if (cnt == M) {	//치킨집 M개를 다 골랐을 경우, 도시의 치킨거리를 구해준다.
		int sum = 0;
		for (int i = 0; i < homeSize; i++) {
			sum += home[i].dist;
		}
		ans = ans > sum ? sum : ans;
		return;
	}
	
	Pos backup[101];
	for (int i = idx; i < storeSize; i++) {	//하나의 선택한 치킨집에 대해
		copyTemp(backup, home);
		if (used[i] == false) {
			used[i] = true;
			for (int j = 0; j < homeSize; j++) {
				int diff = abs(home[j].y - store[i].y) + abs(home[j].x - store[i].x);
				home[j].dist = home[j].dist > diff ? diff : home[j].dist;
			}
			dfs(cnt + 1, i + 1);
			used[i] = false;
			copyTemp(home, backup);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				home[homeSize++] = Pos(i, j);
			}
			else if (arr[i][j] == 2) {
				store[storeSize++] = Pos(i, j);
			}
		}
	}
	dfs(0,0);
	printf("%d", ans);
	return 0;
}