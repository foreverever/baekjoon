//#include <iostream>
//#include <queue>
//#include <utility>
//#define MAX 1001
//using namespace std;
//int n, m;
//int box[MAX][MAX];
//int dy[4] = { -1,1,0,0 };
//int dx[4] = { 0,0,-1,1 };
//int days, cnt;
//queue <pair<int, int> > q;
//
//void bfs() {
//	while (!q.empty()) {
//		for (int i = 0; i < 4; i++) {
//			int nY = q.front().first + dy[i];
//			int nX = q.front().second + dx[i];
//			if (nY < 0 || nX < 0 || nY >= n || nX >= m) continue;
//			if (box[nY][nX] == 0) {
//				box[nY][nX] = 1;
//				q.push(make_pair(nY, nX));
//			}
//		}
//		q.pop();
//		cnt--;
//		if (cnt == 0) {
//			days++;
//			cnt = q.size();
//		}
//	}
//}
//
//bool checkBox() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (box[i][j] == 0) {
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//int main() {
//	cin >> m >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> box[i][j];
//			if (box[i][j] == 1) {
//				q.push(make_pair(i, j));
//				cnt++;
//			}
//		}
//	}
//	//시작지점에 대한 일수는 빼준다
//	if (cnt > 0) {
//		days--;
//	}
//	bfs();
//	//기존 토마토가 모두 익었다면,
//	if (checkBox()) {
//		cout << days;
//	}
//	else {
//		cout << -1;
//	}
//	return 0;
//}