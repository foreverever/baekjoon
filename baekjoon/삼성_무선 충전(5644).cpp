//#include <iostream>
//#include <vector>
//#include <utility>
//#include <math.h>
//#include <algorithm>
//using namespace std;
//int dy[5] = { 0,-1,0, 1,0 };
//int dx[5] = { 0,0,1,0,-1 };
//int T;
//int M, A;
//int ans;
//int sum = -2e9;
//vector<int> aMove, bMove; // a,b 이동방향
//pair<int, int> aLocation, bLocation;
//struct BC
//{
//	int x, y;
//	int range;
//	int power;
//	bool Aused;
//	bool Bused;
//	bool check;
//};
//vector<BC> bc;	//bc
//
//void input() {
//	cin >> M >> A;
//	aMove.clear();
//	bMove.clear();
//	//처음 위치도 체크하므로 '이동하지않음'을 맨 처음에 넣어준다.
//	aMove.push_back(0);
//	bMove.push_back(0);
//	for (int i = 0; i < M; i++) {
//		int input;
//		cin >> input;
//		aMove.push_back(input);
//	}
//	for (int i = 0; i < M; i++) {
//		int input;
//		cin >> input;
//		bMove.push_back(input);
//	}
//	for (int i = 0; i < A; i++) {
//		BC b;
//		int x, y, r, p;
//		cin >> x >> y >> r >> p;
//		b = { x,y,r,p,false,false,false };
//		bc.push_back(b);
//	}
//}
//
//bool isPossibeConnect(int x, int y, BC bc) {
//	return (abs(x - bc.x) + abs(y - bc.y)) <= bc.range;
//}
//
//bool cmp(BC bc1, BC bc2) {
//	return bc1.power < bc2.power;
//}
//
//void dfs(int cnt, int result) {
//	if (cnt == 2) {
//		sum = result > sum ? result : sum;
//		return;
//	}
//	//B
//	if (cnt == 1) {
//		for (int i = 0; i < bc.size(); i++) {
//			if (bc[i].Bused == true && bc[i].check == false) {
//				dfs(cnt + 1, result + bc[i].power);
//			}
//		}
//	}
//	//A
//	if (cnt == 0) {
//		for (int i = 0; i < bc.size(); i++) {
//			if (bc[i].Aused == true) {
//				bc[i].check = true;
//				dfs(cnt + 1, result + bc[i].power);
//				bc[i].check = false;
//			}
//		}
//	}
//	dfs(cnt + 1, result);
//}
//void findAns() {
//	aLocation = { 1,1 };
//	bLocation = { 10,10 };
//	//각 타임마다
//	for (int i = 0; i <= M; i++) {
//		for (int dir = 0; dir < 5; dir++) {
//			//A이동
//			if (aMove[i] == dir) {
//				int nx = aLocation.first + dx[dir];
//				int ny = aLocation.second + dy[dir];
//				if (nx < 1 || ny < 1 || nx>10 || ny>10) continue;
//				aLocation.first = nx;
//				aLocation.second = ny;
//			}
//			//B이동
//			if (bMove[i] == dir) {
//				int nx = bLocation.first + dx[dir];
//				int ny = bLocation.second + dy[dir];
//				if (nx < 1 || ny < 1 || nx>10 || ny>10) continue;
//				bLocation.first = nx;
//				bLocation.second = ny;
//			}
//		}
//		//A와 연결할 수 있는 충전소 찾기
//		for (int j = 0; j < A; j++) {
//			if (isPossibeConnect(aLocation.first, aLocation.second, bc[j])) {
//				bc[j].Aused = true;
//			}
//		}
//		//B와 연결할 수 있는 충전소 찾기
//		for (int j = 0; j < A; j++) {
//			if (isPossibeConnect(bLocation.first, bLocation.second, bc[j])) {
//				bc[j].Bused = true;
//			}
//		}
//		//A,B 최적 충전소 찾기
//		dfs(0, 0);
//		ans += sum;
//		sum = -2e9;
//		//used 초기화
//		for (int i = 0; i < bc.size(); i++) {
//			bc[i].Aused = false;
//			bc[i].Bused = false;
//		}
//	}
//}
//
//int main() {
//	cin >> T;
//	for (int t = 1; t <= T; t++) {
//		input();
//		findAns();
//		cout << "#" << t << ' ' << ans << '\n';
//		bc.clear();
//		ans = 0;
//	}
//	return 0;
//}
//
////////////////////////////////////////// A,B 움직이는 경우 if문으로 작성(가독성은 더 좋을 수도) //////////////////////////////////////// 
////#include <iostream>
////#include <vector>
////#include <utility>
////#include <math.h>
////#include <algorithm>
////#define UP 1
////#define RIGHT 2
////#define DOWN 3
////#define LEFT 4
////using namespace std;
////
////int T;
////int M, A;
////int ans;
////int sum = -2e9;
////vector<int> aMove, bMove; // a,b 이동방향
////pair<int, int> aLocation, bLocation;
////struct BC
////{
////	int x, y;
////	int range;
////	int power;
////	bool Aused;
////	bool Bused;
////	bool check;
////};
////vector<BC> bc;	//bc
////
////void input() {
////	cin >> M >> A;
////	aMove.clear();
////	bMove.clear();
////	//처음 위치도 체크하므로 '이동하지않음'을 맨 처음에 넣어준다.
////	aMove.push_back(0);
////	bMove.push_back(0);
////	for (int i = 0; i < M; i++) {
////		int input;
////		cin >> input;
////		aMove.push_back(input);
////	}
////	for (int i = 0; i < M; i++) {
////		int input;
////		cin >> input;
////		bMove.push_back(input);
////	}
////	for (int i = 0; i < A; i++) {
////		BC b;
////		int x, y, r, p;
////		cin >> x >> y >> r >> p;
////		b = { x,y,r,p,false,false,false };
////		bc.push_back(b);
////	}
////}
////
////bool isPossibeConnect(int x, int y, BC bc) {
////	return (abs(x - bc.x) + abs(y - bc.y)) <= bc.range;
////}
////
////bool cmp(BC bc1, BC bc2) {
////	return bc1.power < bc2.power;
////}
////
////void dfs(int cnt, int result) {
////	if (cnt == 2) {
////		sum = result > sum ? result : sum;
////		return;
////	}
////	//B
////	if (cnt == 1) {
////		for (int i = 0; i < bc.size(); i++) {
////			if (bc[i].Bused == true && bc[i].check == false) {
////				dfs(cnt + 1, result + bc[i].power);
////			}
////		}
////	}
////	//A
////	if (cnt == 0) {
////		for (int i = 0; i < bc.size(); i++) {
////			if (bc[i].Aused == true) {
////				bc[i].check = true;
////				dfs(cnt + 1, result + bc[i].power);
////				bc[i].check = false;
////			}
////		}
////	}
////	dfs(cnt + 1, result);
////}
////void findAns() {
////	aLocation = { 1,1 };
////	bLocation = { 10,10 };
////	//각 타임마다
////	for (int i = 0; i <= M; i++) {
////		//A이동
////		if (aMove[i] == UP && aLocation.second - 1 >= 1) {
////			aLocation.second--;
////		}
////		if (aMove[i] == RIGHT && aLocation.first + 1 <= 10) {
////			aLocation.first++;
////		}
////		if (aMove[i] == DOWN && aLocation.second + 1 <= 10) {
////			aLocation.second++;
////		}
////		if (aMove[i] == LEFT && aLocation.first - 1 >= 1) {
////			aLocation.first--;
////		}
////		//A연결할 수 있는 충전소 찾기
////		for (int j = 0; j < A; j++) {
////			if (isPossibeConnect(aLocation.first, aLocation.second, bc[j])) {
////				bc[j].Aused = true;
////			}
////		}
////		//B이동
////		if (bMove[i] == UP && bLocation.second - 1 >= 1) {
////			bLocation.second--;
////		}
////		if (bMove[i] == RIGHT && bLocation.first + 1 <= 10) {
////			bLocation.first++;
////		}
////		if (bMove[i] == DOWN && bLocation.second + 1 <= 10) {
////			bLocation.second++;
////		}
////		if (bMove[i] == LEFT && bLocation.first - 1 >= 1) {
////			bLocation.first--;
////		}
////		//B와 연결할 수 있는 충전소 찾기
////		for (int j = 0; j < A; j++) {
////			if (isPossibeConnect(bLocation.first, bLocation.second, bc[j])) {
////				bc[j].Bused = true;
////			}
////		}
////		//A,B 최적 충전소 찾기
////		dfs(0, 0);
////		ans += sum;
////		sum = -2e9;
////		//used 초기화
////		for (int i = 0; i < bc.size(); i++) {
////			bc[i].Aused = false;
////			bc[i].Bused = false;
////		}
////	}
////}
////
////void output() {
////	cout << M << ' ' << A << '\n';
////	for (int i = 0; i <= M; i++) {
////		cout << aMove[i];
////	}
////	cout << '\n';
////	for (int i = 0; i <= M; i++) {
////		cout << bMove[i];
////	}
////	cout << '\n';
////	for (int i = 0; i < bc.size(); i++) {
////		cout << bc[i].x << bc[i].y << bc[i].range << bc[i].power;
////		cout << '\n';
////	}
////}
////
////int main() {
////	cin >> T;
////	for (int t = 1; t <= T; t++) {
////		input();
////		findAns();
////		cout << "#" << t << ' ' << ans << '\n';
////		bc.clear();
////		ans = 0;
////	}
////	return 0;
////}