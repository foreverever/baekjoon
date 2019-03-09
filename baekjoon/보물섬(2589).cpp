#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int N, M, ans = -2e9;
char arr[51][51];
int dist[51][51];
bool visited[51][51];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y, x;
	pos(int y, int x) {
		this->y = y;
		this->x = x;
	}
	pos() {}
};

queue <pos> q;

void bfs(pos p) {
	int cnt = 0;
	q.push(p);

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int my = cur.y + dy[i];
			int mx = cur.x + dx[i];
			if (my < 0 || mx < 0 || my >= N || mx >= M) continue;
			if (arr[my][mx] == 'L' && visited[my][mx] == false) {
				q.push(pos(my, mx));
				visited[my][mx] = true;
				dist[my][mx] = dist[cur.y][cur.x] + 1;
				cnt = cnt < dist[my][mx] ? dist[my][mx] : cnt;
			}
		}
	}
	ans = ans < cnt ? cnt : ans;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &arr[i][j]);	//scanf 문자로 받으면, 엔터값도 문자로 받게 되서 입력 에러 발생 %c 앞에 공백을 추가하면 white space를 구분자로 인식해서 해결됨
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'L' && visited[i][j] == false) {
				visited[i][j] = true;
				bfs(pos(i, j));
				memset(visited, false, sizeof(visited));
				memset(dist, 0, sizeof(dist));
			}
		}
	}
	printf("%d", ans);
	return 0;
}