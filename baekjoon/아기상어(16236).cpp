#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct Pos {
	int y, x;
};

struct Fish {
	int eat = 0, dist = 0;	//eat : ���� ũ�⿡�� �Ʊ�� ���� ����� ����
	int y, x, size;
	Fish(int y, int x, int dist, int size) {
		this->y = y;
		this->x = x;
		this->dist = dist;	//�Ʊ���κ��� �ּ� �Ÿ�
		this->size = size;	//�Ʊ��� Ȥ�� ������� ũ��
	}
	Fish() {}
};
int arr[21][21], dist[21][21];
bool visit[21][21];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N;
queue<Pos> q;
Fish shark;

struct cmp {
	bool operator()(Fish &f1, Fish &f2) {
		if (f1.dist == f2.dist) {
			if (f1.y == f2.y) {
				return f1.x > f2.x;
			}
			return f1.y > f2.y;
		}
		return f1.dist > f2.dist;
	}
};

bool bfs() {
	q.push({ shark.y,shark.x });
	visit[shark.y][shark.x] = true;
	priority_queue<Fish, vector<Fish>, cmp> pq;

	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int my = cur.y + dy[k];
			int mx = cur.x + dx[k];
			if (my < 0 || mx < 0 || my >= N || mx >= N) continue;
			if (visit[my][mx] == false && arr[my][mx] <= shark.size) {
				visit[my][mx] = true;
				dist[my][mx] = dist[cur.y][cur.x] + 1;
				q.push({ my,mx });
				if (arr[my][mx] > 0 && arr[my][mx] < shark.size) {
					pq.push(Fish(my, mx, dist[my][mx], arr[my][mx]));
				}
			}
		}
	}

	
	if (!pq.empty()) {	//�켱���� ť �� ���� ����Ⱑ ���� �Ʊ�� ���� ���� ���� �� �ִ� �����
		Fish food = pq.top();
		arr[shark.y][shark.x] = 0;
		shark.y = food.y;
		shark.x = food.x;
		shark.dist += food.dist;
		if (++shark.eat == shark.size) {
			shark.size++;
			shark.eat = 0;	//��� ũ�� 1 ���� ��, ���ݱ��� ���� ���� �ʱ�ȭ
		}
		memset(dist, 0, sizeof(dist));
		memset(visit, false, sizeof(visit));
		return true;
	}
	return false;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 9) {
				shark.size = 2;
				shark.y = i;
				shark.x = j;
			}
		}
	}
	while (bfs());
	printf("%d", shark.dist);
	return 0;
}