//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <string.h>
//#define MAX 21
//using namespace std;
//int T;
//int N, x;
//int ans;
//vector<vector<int> > map;
//vector<int> width, height;
//int checkRightBridge[MAX], checkLeftBridge[MAX];
//
//void makeMap() {
//	vector<int> e;
//	e.resize(N);
//	for (int i = 0; i < N; i++) {
//		map.push_back(e);
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//}
//
//void checkInstallBridge(vector<int> path) {
//	//다리 설치 체크 배열 초기화
//	memset(checkRightBridge, false, sizeof(checkRightBridge));
//	memset(checkLeftBridge, false, sizeof(checkLeftBridge));
//
//	//설치할 수 없는 경우
//	for (int i = 0; i < path.size() - 1; i++) {
//		if (abs(path[i] - path[i + 1]) > 1) return;
//	}
//	//모두 평지인 경우
//	int check = 0;
//	for (int i = 0; i < path.size() - 1; i++) {
//		if (path[i] == path[i + 1]) check++;
//	}
//	if (check == path.size() - 1) {
//		ans++;
//		return;
//	}
//
//	//오른쪽 위 방향 다리 설치인 경우
//	for (int i = 0; i < path.size() - 1; i++) {
//		if (path[i] == path[i + 1] - 1) {
//			int s = i + 1 - x;
//			int e = i;
//			if (s < 0) return;
//			for (int j = s; j < e; j++) {
//				if (path[j] != path[j + 1]) return;
//			}
//			for (int j = s; j <= e; j++) {
//				checkRightBridge[j] = true;
//			}
//		}
//	}
//	//왼쪽 위 방향 다리 설치인 경우
//	for (int i = 0; i < path.size() - 1; i++) {
//		if (path[i] == path[i + 1] + 1) {
//			int s = i + 1;
//			int e = i + x;
//			if (e >= N) return;
//			for (int j = s; j < e; j++) {
//				if (path[j] != path[j + 1]) return;
//			}
//			for (int j = s; j <= e; j++) {
//				checkLeftBridge[j] = true;
//			}
//		}
//	}
//	//다리 설치 중복된 경우
//	for (int i = 0; i < MAX; i++) {
//		if (checkRightBridge[i] && checkLeftBridge[i]) return;
//	}
//	ans++;
//}
//
//int main() {
//	cin >> T;
//	for (int i = 1; i <= T; i++) {
//		cin >> N >> x;
//		makeMap();
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				//가로
//				width.push_back(map[i][j]);
//				//세로
//				height.push_back(map[j][i]);
//			}
//			//활주로 설치 유무 판단(가로,세로)
//			checkInstallBridge(width);
//			checkInstallBridge(height);
//			width.clear();
//			height.clear();
//		}
//		cout << "#" << i << ' ' << ans << '\n';
//		ans = 0;
//		map.clear();
//	}
//	return 0;
//}