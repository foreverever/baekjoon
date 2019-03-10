#include <iostream>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

struct area {
	int value, group, y, x;
	area(int val, int group, int y, int x) {
		this->value = val;
		this->group = group;
		this->y = y;
		this->x = x;
	}
	area() {}
};

queue<area> q;
int N, L, R, ans;
int cnt;	//��ü �α��̵� ȸ��, ���� 0�̶�� while�� ����
area arr[51][51];
bool visited[51][51];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool isPossibleMove(int cur, int next) {
	int diff = abs(cur - next);
	return diff >= L && diff <= R;
}

void bfs(area &a) {	//�ּҰ����� �޾ƾ� a.group�Ҷ�, arr�� �ִ� ��¥ ���� �����
	int areaNum = 1; //���� �̵��ؾ� �� ���� ����
	int sum = 0;	//���� �α� ��
	q.push(a);
	a.group = 1;

	while (!q.empty()) {
		area cur = q.front();	//queue�� reference�� �ƴ� value �����̹Ƿ�, cur�� ���� �����Ѵٰ� �ش� arr�迭 ���� ������� �ʴ´�
		sum += cur.value;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int my = cur.y + dy[k];
			int mx = cur.x + dx[k];
			if (my < 0 || mx < 0 || my >= N || mx >= N) continue;
			if (visited[my][mx] == false && isPossibleMove(cur.value, arr[my][mx].value)) {
				visited[my][mx] = true;
				arr[my][mx].group = 1;
				q.push(arr[my][mx]);
				areaNum++;
				cnt++;
			}
		}
	}
	if (areaNum > 1) {
		int updatedValue = sum / areaNum;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j].group == 1) {
					arr[i][j].value = updatedValue;
					arr[i][j].group = 0;
				}
			}
		}
	}
	else a.group = 0;
}

int main() {
	scanf("%d %d %d", &N, &L, &R);
	int val;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &val);
			arr[i][j] = area(val, 0, i, j);
		}
	}
	while (1) {
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == false) {
					visited[i][j] = true;
					bfs(arr[i][j]);
				}
			}
		}
		if (cnt == 0) break;
		ans++;
		memset(visited, false, sizeof(visited));
	}
	printf("%d", ans);
	return 0;
}