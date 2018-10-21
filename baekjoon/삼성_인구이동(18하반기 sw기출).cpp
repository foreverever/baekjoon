#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>
#include <math.h>
using namespace std;

int N, L, R;
vector<vector<int> > originMap, checkMap;
vector<vector<bool> > check;
vector<int> calc, resultInfo;
queue<pair<int, int> > q;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int cnt, ans;
void input() {
	vector<int> e;
	vector<bool> e1;
	e.resize(N);
	e1.resize(N);
	for (int i = 0; i < N; i++) {
		originMap.push_back(e);
		checkMap.push_back(e);
		check.push_back(e1);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> originMap[i][j];
		}
	}
}

void output(vector<vector<int> > v) {
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool isPossibleToGo(int v1, int v2) {
	int val = abs(v1 - v2);
	if (val >= L && val <= R) {
		return true;
	}
	return false;
}

void getAvg() {
	int sum = 0;
	for (int i = 0; i < calc.size(); i++) {
		sum += calc[i];
	}
	resultInfo.push_back(sum / calc.size());
	calc.clear();
}

void drawMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < resultInfo.size(); k++) {
				if (checkMap[i][j] - 1 == k) {
					originMap[i][j] = resultInfo[k];
				}
			}
		}
	}
}

void bfs() {
	while (!q.empty()) {
		for (int k = 0; k < 4; k++) {
			int ny = q.front().first + dy[k];
			int nx = q.front().second + dx[k];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (check[ny][nx] == false && isPossibleToGo(originMap[ny][nx], originMap[q.front().first][q.front().second])) {
				checkMap[ny][nx] = cnt;
				check[ny][nx] = true;
				calc.push_back(originMap[ny][nx]);
				q.push(make_pair(ny, nx));
			}
		}
		q.pop();
	}
}

void initCheck() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = false;
		}
	}
}
void findAns() {
	while (1) {
		cnt = 0;
		//한 타임에 대해
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == false) {
					cnt++;	//영역 번호 및 개수
					checkMap[i][j] = cnt;
					check[i][j] = true;
					calc.push_back(originMap[i][j]);
					q.push(make_pair(i, j));
					bfs();
					getAvg();
				}
			}
		}
		if (cnt == N * N) {
			return;
		}
		ans++;
		drawMap();
		initCheck();
		resultInfo.clear();
	}
}

int main() {
	cin >> N >> L >> R;
	input();
	findAns();
	cout << ans;
	return 0;
}