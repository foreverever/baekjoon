#include <iostream>
#include <vector>
#include <string.h>
#define UP 0
#define DOWN 2
#define LEFT 1
#define RIGHT 3
using namespace std;

int N, M, ans=2e9;
int arr[9][9], backup[9][9];
int dirInfo[6] = { 0,4,2,4,4,1 };	//�� cctv�� ȸ�� ����� �� (�ε����� cctv��ȣ ��ġ�� ���� 0�ε����� 0�� ����)

struct CCTV {
	int type, y, x;
	CCTV(int type, int y, int x) {
		this->type = type;
		this->y = y;
		this->x = x;
	}
	CCTV() {}
};

vector<CCTV> cctvs;

void update(int dir, CCTV cur) {
	dir %= 4;	
	if (dir == UP) {
		for (int i = cur.y; i >= 0; i--) {
			if (arr[i][cur.x] == 6) break;
			if (arr[i][cur.x] == 0) arr[i][cur.x] = -1;
		}
	}
	if (dir == DOWN) {
		for (int i = cur.y; i < N; i++) {
			if (arr[i][cur.x] == 6) break;
			if (arr[i][cur.x] == 0) arr[i][cur.x] = -1;
		}
	}
	if (dir == LEFT) {
		for (int i = cur.x; i >= 0; i--) {
			if (arr[cur.y][i] == 6) break;
			if (arr[cur.y][i] == 0) arr[cur.y][i] = -1;
		}
	}
	if (dir == RIGHT) {
		for (int i = cur.x; i < M; i++) {
			if (arr[cur.y][i] == 6) break;
			if (arr[cur.y][i] == 0) arr[cur.y][i] = -1;
		}
	}
}

void copyMap(int to[9][9], int from[9][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			to[i][j] = from[i][j];
		}
	}
}

void dfs(int cctvIdx) {
	if (cctvIdx == cctvs.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0) cnt++;
			}
		}
		ans = ans > cnt ? cnt : ans;
		return;
	}
	int backup[9][9];	//������ �ƴ� ���������� �����ؾ�,, ��͸��� �����Ǵ� ���ÿ����� �ش� ������ ���� �� ����
	int type = cctvs[cctvIdx].type;	//Ư�� cctv ã��
	for (int dir = 0; dir < dirInfo[type]; dir++) {	//Ư�� cctv�� ��� ȸ�� ��쿡 ����
		copyMap(backup, arr);
		if (type == 1) {
			update(dir, cctvs[cctvIdx]);	//Ư�� ���⿡ ���� update
			dfs(cctvIdx + 1);
		}
		else if (type == 2) {
			update(dir, cctvs[cctvIdx]);
			update(dir + 2, cctvs[cctvIdx]);
			dfs(cctvIdx + 1);
		}
		else if (type == 3) {
			update(dir, cctvs[cctvIdx]);
			update(dir + 3, cctvs[cctvIdx]);
			dfs(cctvIdx + 1);
		}
		else if (type == 4) {
			update(dir, cctvs[cctvIdx]);
			update(dir + 1, cctvs[cctvIdx]);
			update(dir + 3, cctvs[cctvIdx]);
			dfs(cctvIdx + 1);
		}
		else if (type == 5) {
			update(dir, cctvs[cctvIdx]);
			update(dir + 1, cctvs[cctvIdx]);
			update(dir + 2, cctvs[cctvIdx]);
			update(dir + 3, cctvs[cctvIdx]);
			dfs(cctvIdx + 1);
		}
		copyMap(arr, backup);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 6 && arr[i][j] != 0) {
				cctvs.push_back(CCTV(arr[i][j], i, j));
			}
		}
	}
	dfs(0);
	printf("%d", ans);
	return 0;
}