#include <iostream>
#include <string.h>
#include <vector>
#define RANGE 7
#define W 'W'
#define B 'B'
using namespace std;

int N, M;
char board[51][51];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
}

bool isNotRange(int y, int x) {
	return y + RANGE >= N || x + RANGE >= M;
}

vector<vector<char> > cutBoard(int y, int x) {
	vector<vector<char> > chess;
	vector<char> e;
	e.resize(8);
	for (int i = 0; i < 8; i++) chess.push_back(e);

	for (int i = y; i <= y + RANGE; i++) {
		for (int j = x; j <= x + RANGE; j++) {
			chess[i - y][j - x] = board[i][j];
		}
	}
	return chess;
}

int calc(char first, char second, vector<vector<char> > chess) {
	int cnt = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				if (chess[i][j] != first) {
					chess[i][j] = first;
					cnt++;
				}
			}
			else {
				if (chess[i][j] != second) {
					chess[i][j] = second;
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int getChangeNum(vector<vector<char> > &chess) {
	int a = calc(W, B, chess);	//ü���� ù��° ���� W�̸�, ù��°�� �ȹٲٴ� ��� || ù��° ���� B�̸�, ù��°�� �ٲٴ� ��찡 ��
	int b = calc(B, W, chess);	//ü���� ù��° ���� B�̸�, ù��°�� �ȹٲٴ� ��� || ù��° ���� W�̸�, ù��°�� �ٲٴ� ��찡 ��
	return a > b ? b : a;
}

int findAns() {
	int ans = 2e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (isNotRange(i, j)) continue;
			vector<vector<char> > chess = cutBoard(i, j);
			int change = getChangeNum(chess);
			ans = change < ans ? change : ans;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	input();
	cout << findAns();
	return 0;
}