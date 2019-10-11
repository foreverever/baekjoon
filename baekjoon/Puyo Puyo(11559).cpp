#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <stack>
#define DOT '.'
using namespace std;

char board[12][6];	//게임 판
bool visit[12][6];	//방문 체크
int cnt[12][6];	//4개 이상 체크
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Pos {
	int y, x;
	Pos(int y, int x) : y(y), x(x) {};
};

void bfs(int y, int x, int plus) {
	queue<Pos> q;
	q.push(Pos(y, x));
	visit[y][x] = true;
	cnt[y][x] = plus;

	while (!q.empty()) {
		Pos cur = q.front(); q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];
			if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6) continue;
			if (board[ny][nx] == board[y][x] && !visit[ny][nx]) {
				cnt[ny][nx] = ++plus;
				visit[ny][nx] = true;
				q.push(Pos(ny, nx));
			}
		}
	}
}

void deleteBlock(int y, int x, char origin) {
	queue<Pos> q;
	q.push(Pos(y, x));
	board[y][x] = DOT;
	visit[y][x] = true;

	while (!q.empty()) {
		Pos cur = q.front(); q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];
			if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6) continue;
			if (board[ny][nx] == origin && !visit[ny][nx]) {
				board[ny][nx] = DOT;
				visit[ny][nx] = true;
				q.push(Pos(ny, nx));
			}
		}
	}
}

void output() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

void down(int curX) {
	//스택으로 y축의 값들을 넣어준 후, '.'이 아니면 pop, 알파벳이면 밑에서부터 채워주도록 한다.
	stack<char> st;
	int cntDot = 0;

	for (int i = 0; i < 12; i++) {
		if (board[i][curX] == DOT) cntDot++;
		st.push(board[i][curX]);
	}

	int curY = 11;
	while (!st.empty()) {
		if (st.top() != DOT) {
			board[curY][curX] = st.top();
			st.pop();
			curY--;
		}
		else st.pop();
	}
	for (int i = 0; i < cntDot; i++) board[i][curX] = DOT;
}

int ans = 0;
void findAns() {

	while (1) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != DOT && !visit[i][j]) {
					bfs(i, j, 1);
				}
			}
		}
		memset(visit, false, sizeof(visit));	//카운트 체크 했으므로, 방문 체크 초기화

		//4개 이상인 블록에 대해 지워주는 작업(.으로)
		int check = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (cnt[i][j] >= 4 && !visit[i][j]) {
					deleteBlock(i, j, board[i][j]);
					check++;
				}
			}
		}
		if (check == 0) return;
		ans++;
		memset(visit, false, sizeof(visit));
		memset(cnt, 0, sizeof(cnt));

		//지워진 블록을 밑으로 내린다
		for (int j = 0; j < 6; j++) {
			down(j);
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}
	findAns();
	cout << ans;
	return 0;
}