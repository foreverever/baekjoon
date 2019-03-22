#include <iostream>
#include <map>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
using namespace std;

struct Cleaner {
	int y, x, dir, clear = 0, check = 0;

	Cleaner(int y, int x, int dir) {
		this->y = y;
		this->x = x;
		this->dir = dir;
	}

	Cleaner() {}
};

struct Pos {
	int y, x;
};

int N, M;
int arr[51][51];
bool visit[51][51];
map<int, Pos> direction, back;
Cleaner cleaner;

void findAns() {
	visit[cleaner.y][cleaner.x] = true;
	cleaner.clear++;
	//�ϳ��� ���⿡ ����
	while (1) {
		int nDir = (cleaner.dir + 3) % 4;	//���� ������ ����
		int ny = cleaner.y + direction[nDir].y;	//���� y��ǥ
		int nx = cleaner.x +direction[nDir].x;	//���� x��ǥ
		//���� ��ġ�� û���� �� �ִٸ�
		if (visit[ny][nx] == false && arr[ny][nx] == 0) {
			visit[ny][nx] = true;
			cleaner.y = ny; cleaner.x = nx; cleaner.dir = nDir;
			cleaner.clear++;
			cleaner.check = 0;
		}
		else {
			cleaner.check++;
			cleaner.dir = nDir;
		}

		//��� ���� �����ٸ�
		if (cleaner.check == 4) {
			//�ڿ� ���� �ִٸ� ����
			int by = cleaner.y + back[cleaner.dir].y;
			int bx = cleaner.x + back[cleaner.dir].x;
			if (arr[by][bx] == 1) return;
			//�ƴϸ� �ڷ� �̵�
			cleaner.y = by;
			cleaner.x = bx;
			cleaner.check = 0;
		}
	}
}

int main() {
	int y, x, dir;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &y, &x, &dir);
	cleaner = Cleaner(y, x, dir);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//���� ���� ��ǥ ���Ű� �ʱ�ȭ
	direction[NORTH] = { -1,0 };
	direction[EAST] = { 0,1 };
	direction[SOUTH] = { 1,0 };
	direction[WEST] = { 0,-1 };

	//���� ��ġ �������� �ڷ� ���ư��� ��ǥ ���Ű� �ʱ�ȭ
	back[NORTH] = { 1,0 };
	back[EAST] = { 0,-1 };
	back[SOUTH] = { -1,0 };
	back[WEST] = { 0,1 };

	findAns();
	printf("%d", cleaner.clear);
	return 0;
}