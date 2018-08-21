#include <iostream>
#include <queue>
#include <utility>
#define MAX 101

using namespace std;

int map[MAX][MAX];	//��
int distMap[MAX][MAX];	//����ġ �迭
bool checkMap[MAX][MAX];	//�湮 üũ �迭(false�� �ʱ�ȭ)
int n, m;	//�迭 ����	(n:����, m:����)
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

//����üũ �Լ�
bool isNotInsideMap(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m) {
		return true;
	}
	return false;
}

//BFS�Լ�
void bfs(int i, int j) {
	queue <pair<int, int> > q;
	q.push(make_pair(i, j));
	checkMap[i][j] = true;	//�湮 ǥ��
	distMap[i][j] += 1;
	//queue�� ������� �� ���� Ž��
	while (!q.empty()) {
		//������ġ���� �����¿� Ž��
		for (int k = 0; k < 4; k++) {
			int y = q.front().first + dy[k];
			int x = q.front().second + dx[k];
			if (isNotInsideMap(y, x)) continue;
			if (map[y][x] == 1 && checkMap[y][x] == false) {
				q.push(make_pair(y, x));
				checkMap[y][x] = true;
				distMap[y][x] = distMap[q.front().first][q.front().second] + 1;
			}
		}
		q.pop();
	}
}

//�̷�Ž�� ��������� ����
int start() {
	if (map[0][0] == 1 && checkMap[0][0] == false) {
		bfs(0, 0);
		return distMap[n - 1][m - 1];
	}
}

int main() {
	cin >> n >> m;
	//�� ���� �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int ans = start();
	cout << ans;
	return 0;
}
