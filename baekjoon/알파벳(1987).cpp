#include <iostream>
#include <vector>
#define MAX 20

using namespace std;

char board[MAX][MAX];
int N, M;
int maxCnt = 1;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector <char> alphabet;

//���� üũ
bool isNotInside(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M) {
		return true;
	}
	return false;
}

//�湮 ���� üũ
bool isPossibleVisit(int i, int j) {
	for (int k = 0; k < alphabet.size(); k++) {
		if (board[i][j] == alphabet[k]) {
			return false;
		}
	}
	return true;
}

//�湮 Ƚ�� �ִ밪 ã��
void findMax(int cnt) {
	maxCnt = cnt > maxCnt ? cnt : maxCnt;
}

//����ĭ �ʱ�ȭ
void initBoard() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	alphabet.push_back(board[0][0]);
}

//DFS
void dfs(int i, int j, int cnt) {
	for (int k = 0; k < 4; k++) {
		int y = i + dy[k];
		int x = j + dx[k];
		if (isNotInside(y, x)) continue;
		if (isPossibleVisit(y, x)) {
			alphabet.push_back(board[y][x]);
			findMax(cnt + 1);
			dfs(y, x, cnt + 1);
			alphabet.pop_back();
		}
	}
	return;
}

int main() {
	initBoard();
	dfs(0, 0, 1);
	cout << maxCnt;
	return 0;
}