//#include <iostream>
//#include <queue>
//#include <utility>
//#define MAX 8
//
//using namespace std;
//int N, M;
//int ans = -2e9;	//정답 (MAX값 찾기)
//int map[MAX][MAX];	//기본 맵
//int testMap[MAX][MAX];	//바이러스 유포 맵
//int dy[4] = { -1,1,0,0 };
//int dx[4] = { 0,0,-1,1 };
//
//void bfs(int i, int j);
//void findMaxNum();
//void virusStart();
//
////맵 정보 입력 함수
//void inputMap() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//		}
//	}
//}
//
////범위 체크 함수
//bool isNotInside(int i, int j) {
//	if (i < 0 || j < 0 || i >= N || j >= M) {
//		return true;
//	}
//	return false;
//}
//
////바이러스 유포 맵 갱신 함수
//void createTestMap() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			testMap[i][j] = map[i][j];
//		}
//	}
//}
//
////벽 생성 함수
//void createWall(int cnt) {
//	if (cnt == 3) {
//		createTestMap();
//		virusStart();
//		return;
//	}
//	else {
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//				if (map[i][j] == 0) {
//					map[i][j] = 1;
//					createWall(cnt + 1);
//					map[i][j] = 0;
//				}
//			}
//		}
//	}
//}
//
////바이러스 유포 시작
//void virusStart() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (map[i][j] == 2) {
//				bfs(i, j);
//			}
//		}
//	}
//	findMaxNum();
//}
//
////BFS
//void bfs(int i, int j) {
//	queue <pair<int, int> > q;
//	q.push(make_pair(i, j));
//	while (!q.empty()) {
//		for (int k = 0; k < 4; k++) {
//			int y = q.front().first + dy[k];
//			int x = q.front().second + dx[k];
//			if (isNotInside(y, x)) continue;
//			if (testMap[y][x] == 0) {
//				testMap[y][x] = 2;
//				q.push(make_pair(y, x));
//			}
//		}
//		q.pop();
//	}
//}
//
////0의 개수 최대값 구하기
//void findMaxNum() {
//	int num = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (testMap[i][j] == 0) {
//				num++;
//			}
//		}
//	}
//	ans = num > ans ? num : ans;
//}
//
////시작
//void start() {
//	inputMap();
//	createWall(0);
//}
//
////실행함수
//int main() {
//	cin >> N >> M;
//	start();
//	cout << ans;
//	return 0;
//}