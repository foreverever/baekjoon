//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define MAX 26
//using namespace std;
//
//int N;
//int map[MAX][MAX];
//bool check[MAX][MAX];
//int dy[4] = { -1,1,0,0 };
//int dx[4] = { 0,0,-1,1 };
//vector <int> ans;
//int cnt;
//
//void dfs(int y, int x) {
//	for (int i = 0; i < 4; i++) {
//		int nextY = y + dy[i];
//		int nextX = x + dx[i];
//		if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N) continue;
//		if (map[nextY][nextX] == 1 && check[nextY][nextX] == false) {
//			check[nextY][nextX] = true;
//			cnt++;
//			dfs(nextY, nextX);
//		}
//	}
//}
//
//void findAns() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (map[i][j] == 1 && check[i][j] == false) {
//				check[i][j] = true;
//				cnt = 1;
//				dfs(i, j);
//				ans.push_back(cnt);
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			scanf("%1d", &map[i][j]);
//		}
//	}
//	findAns();
//	sort(ans.begin(), ans.end());
//	cout << ans.size() << '\n';
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << '\n';
//	}
//	return 0;
//}