#include <iostream>
#include <string.h>
#define TALL 1
#define SMALL -1
using namespace std;

int arr[501][501];
int ans;
int n, m, total;	//학생수, 비교횟수, 나보다 키가 크거나 작은 학생 수
bool visit[501];

void dfs(int i, int height) {
	for(int j : arr[i])
	for (int j = 1; j <= n; j++) {
		if (arr[i][j] == height && visit[j] == false) {
			visit[j] = true;
			total++;
			dfs(j, height);
		}
	}
}

int findAns() {
	for (int i = 1; i <= n; i++) {	//각 한명의 학생에 대해
		total = 0;
		dfs(i, TALL);	//i번째 학생보다 큰 학생들 수
		memset(visit, false, sizeof(visit));
		dfs(i, SMALL);	//i번째 학생보다 작은 학생들 수
		memset(visit, false, sizeof(visit));
		if (total == n - 1) ans++;
	}
	return ans;
}

void input() {
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		arr[x][y] = SMALL;	//x기준 y보다 작다
		arr[y][x] = TALL;	//y기준 x보다 크다
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	input();
	cout << findAns();
	return 0;
}
