//#include <iostream>
//#include <queue>
//#include <utility>
//#define MAX 8
//
//using namespace std;
//int N, M;
//int ans = -2e9;	//���� (MAX�� ã��)
//int map[MAX][MAX];	//�⺻ ��
//int testMap[MAX][MAX];	//���̷��� ���� ��
//int dy[4] = { -1,1,0,0 };
//int dx[4] = { 0,0,-1,1 };
//
//void bfs(int i, int j);
//void findMaxNum();
//void virusStart();
//
////�� ���� �Է� �Լ�
//void inputMap() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//		}
//	}
//}
//
////���� üũ �Լ�
//bool isNotInside(int i, int j) {
//	if (i < 0 || j < 0 || i >= N || j >= M) {
//		return true;
//	}
//	return false;
//}
//
////���̷��� ���� �� ���� �Լ�
//void createTestMap() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			testMap[i][j] = map[i][j];
//		}
//	}
//}
//
////�� ���� �Լ�
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
////���̷��� ���� ����
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
////0�� ���� �ִ밪 ���ϱ�
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
////����
//void start() {
//	inputMap();
//	createWall(0);
//}
//
////�����Լ�
//int main() {
//	cin >> N >> M;
//	start();
//	cout << ans;
//	return 0;
//}