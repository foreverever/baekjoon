#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct Pos {
	int y, x;
	Pos(int y, int x) {
		this->y = y;
		this->x = x;
	}
	Pos() {};
};


int tc, N, M;
char arr[1002][1002];
int fire[1002][1002], human[1002][1002];
bool visitF[1002][1002], visitH[1002][1002];
queue<Pos> fq, hq;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int bfs() {
	//�� ���� �����Բ�
	while (!fq.empty()) {
		Pos cur = fq.front();
		fq.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visitF[ny][nx] == false && arr[ny][nx] != '#') {
				visitF[ny][nx] = true;
				fire[ny][nx] = fire[cur.y][cur.x] + 1;
				fq.push(Pos(ny, nx));
			}
		}
	}
	//��� �̵�
	while (!hq.empty()) {
		Pos cur = hq.front();
		hq.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (fire[ny][nx] == 0) {
				if (visitH[ny][nx] == false && arr[ny][nx] == '.') {
					visitH[ny][nx] = true;
					human[ny][nx] = human[cur.y][cur.x] + 1;
					if (ny == 0 || nx == 0 || ny == N - 1 || nx == M - 1) return human[ny][nx] + 1;
					hq.push(Pos(ny, nx));
				}
			}
			else {
				if (visitH[ny][nx] == false && arr[ny][nx] == '.' && fire[ny][nx] > human[cur.y][cur.x] + 1) {
					visitH[ny][nx] = true;
					human[ny][nx] = human[cur.y][cur.x] + 1;
					if (ny == 0 || nx == 0 || ny == N - 1 || nx == M - 1) return human[ny][nx] + 1;
					hq.push(Pos(ny, nx));
				}
			}
		}
	}
	return -1;
}

void init() {
	//�ʱ�ȭ
	while (!hq.empty()) hq.pop();
	while (!fq.empty()) fq.pop();
	memset(visitF, false, sizeof(visitF));
	memset(visitH, false, sizeof(visitH));
	memset(fire, 0, sizeof(fire));
	memset(human, 0, sizeof(human));
}

int main() {
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		scanf("%d %d", &M, &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %c", &arr[i][j]);
				if (arr[i][j] == '@') {
					hq.push(Pos(i, j));
					visitH[i][j] = true;
				}
				else if (arr[i][j] == '*') {
					fq.push(Pos(i, j));
					visitF[i][j] = true;
				}
			}
		}
		Pos h = hq.front();
		if (h.y == 0 || h.x == 0 || h.y == N - 1 || h.x == M - 1) {
			printf("%d\n", 1);
			init();
			continue;
		}
		int ans = bfs();
		if (ans == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
		init();
	}
	return 0;
}

//���� ���� bfs�� �̵�(ĭ���� �����ϴ� �ð��� ���� �迭�� ����)
//�� �̵� �Ϸ� ��, ��� bfs �̵�(ĭ���� �����ϴ� �ð��� ���� �迭�� ����)
//���� ���� ���� �ش� ĭ�� �� �ð� �迭���� 0�̰�, �� ���� ��� �̵� ����
//���� �ִ� ���� �ش� ĭ�� �� �ð��� ��� �ð����� ���� �ÿ��� ��� �̵� ����