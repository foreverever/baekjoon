//#include <iostream>
//#include <utility>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//struct P {
//	int x, y;
//};
//void printP(P p) {
//	cout << p.x;
//}
//bool cmp(P p1, P p2) {
//	return (p1.y < p2.y);
//}
//int main() {
//	//@TEST
//	/*pair<int, int> p;
//	p = make_pair(1, 1);
//	p = { 2, 3};
//	cout << p.first << p.second;*/
//	
//	//@TEST
//	//P p;
//	//p.x = 1;
//	//printP(p);
//
//	//@TEST
//	vector<P> v;
//	P p1, p2;
//	p1 = { 1,3 };
//	p2 = { 4,2 };
//	v.push_back(p1);
//	v.push_back(p2);
//	/*cout << v.back().y;
//	sort(v.begin(), v.end(),cmp);
//	cout << v.size();
//	cout << v.back().y <<'\n';*/
//	if (&v[0] == &p1) {
//		cout << "정답";
//	}
//	return 0;
//}

///////////////////////////////////////////////////////충전기 뻘짓///////////////////////////////////
//#include <iostream>
//#include <vector>
//#include <utility>
//#include <math.h>
//#include <algorithm>
//#define UP 1
//#define RIGHT 2
//#define DOWN 3
//#define LEFT 4
//using namespace std;
//
//int T;
//int M, A;
//int sum;
//vector<int> aMove, bMove; // a,b 이동방향
//pair<int, int> aLocation, bLocation;
//struct BC
//{
//	int x, y;
//	int range;
//	int power;
//	bool used;
//};
//vector<BC> bc, cbA, cbB, result;	//bc, 각 a,b 연결가능 충전기, ab 연결한 충전기
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
//		b = { x,y,r,p,false };
//		bc.push_back(b);
//	}
//}
//
//bool isPossibeConnect(int x, int y, BC cb) {
//	return (abs(x - cb.x) + abs(y - cb.y)) <= cb.range;
//}
//
//bool cmp(BC cb1, BC cb2) {
//	return cb1.power < cb2.power;
//}
//
//void findMaxPower(int n) {
//	//cout << "횟수 : " << n << '\n';
//	//cout << "Asize : " << checkA.size() << '\n' << "Bsize : " << checkB.size() << '\n';
//	//A 연결 가능 충전기가 있을 경우
//	if (cbA.size() > 0) {
//		sort(cbA.begin(), cbA.end(), cmp);
//		for (int i = 0; i < cbA.size(); i++) {
//			result.push_back(cbA[i]);
//		}
//		sort(result.begin(), result.end(), cmp);
//		sum += result.back().power;
//		result.pop_back();
//	}
//
//	//B 연결 가능 충전기가 있을 경우
//	if (cbB.size() > 0) {
//		for (int i = 0; i < cbB.size(); i++) {
//			result.push_back(cbB[i]);
//		}
//		sort(result.begin(), result.end(), cmp);
//		//A도 있을 경우
//		if (cbA.size() > 0) {
//			//A와 중복체크
//			for (int i = result.size() - 1; i >= 0; i--) {
//				int cnt = 0;
//				//중복이 있으면 해당 MAX CB 제거
//				for (int j = 0; j < cbA.size(); j++) {
//					if (result.back().x == cbA[j].x && result.back().y == cbA[j].y) {
//						result.pop_back();
//					}
//					else cnt++;
//				}
//				//중복 없으면 result.back()의 성능이 B의 최대값
//				if (cnt == cbA.size()) {
//					sum += result.back().power;
//					break;
//				}
//			}
//		}
//		//A 없을 경우
//		else {
//			sum += result.back().power;
//		}
//	}
//	cout << "회수 : " << n << ' ' << sum << '\n';
//	result.clear();
//}
//void findAns() {
//	aLocation = { 1,1 };
//	bLocation = { 10,10 };
//	//각 타임마다
//	for (int i = 0; i <= M; i++) {
//		//A이동
//		if (aMove[i] == UP && aLocation.second - 1 >= 1) {
//			aLocation.second--;
//		}
//		if (aMove[i] == RIGHT && aLocation.first + 1 <= 10) {
//			aLocation.first++;
//		}
//		if (aMove[i] == DOWN && aLocation.second + 1 <= 10) {
//			aLocation.second++;
//		}
//		if (aMove[i] == LEFT && aLocation.first - 1 >= 1) {
//			aLocation.first--;
//		}
//		for (int j = 0; j < A; j++) {	//A연결할 수 있는 충전기 찾기
//			if (isPossibeConnect(aLocation.first, aLocation.second, bc[j])) {
//				cbA.push_back(bc[j]);
//			}
//		}
//		//B이동
//		if (bMove[i] == UP && bLocation.second - 1 >= 1) {
//			bLocation.second--;
//		}
//		if (bMove[i] == RIGHT && bLocation.first + 1 <= 10) {
//			bLocation.first++;
//		}
//		if (bMove[i] == DOWN && bLocation.second + 1 <= 10) {
//			bLocation.second++;
//		}
//		if (bMove[i] == LEFT && bLocation.first - 1 >= 1) {
//			bLocation.first--;
//		}
//		for (int j = 0; j < A; j++) {	//B와 연결할 수 있는 충전기 찾기
//			if (isPossibeConnect(bLocation.first, bLocation.second, bc[j])) {
//				cbB.push_back(bc[j]);
//			}
//		}
//		//A,B 최적 충전기 찾기
//		findMaxPower(i);
//		cbA.clear();
//		cbB.clear();
//	}
//}
//void output() {
//	cout << M << ' ' << A << '\n';
//	for (int i = 0; i <= M; i++) {
//		cout << aMove[i];
//	}
//	cout << '\n';
//	for (int i = 0; i <= M; i++) {
//		cout << bMove[i];
//	}
//	cout << '\n';
//	for (int i = 0; i < bc.size(); i++) {
//		cout << bc[i].x << bc[i].y << bc[i].range << bc[i].power;
//		cout << '\n';
//	}
//}
//int main() {
//	cin >> T;
//	for (int t = 1; t <= T; t++) {
//		input();
//		findAns();
//		cout << "#" << t << ' ' << sum << '\n';
//		bc.clear();
//		sum = 0;
//	}
//	return 0;
//}

