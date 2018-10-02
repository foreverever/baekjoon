//#include <iostream>
//#include <vector>
//#include <utility>
//
//using namespace std;
//
//int N;
//int maxProfit = -2e9;
//vector<pair<int, int> > v;
//
//void findAns(int now, int sum) {
//	if (now >= N) {
//		maxProfit = sum > maxProfit ? sum : maxProfit;
//		return;
//	}
//	for (int i = now; i < N; i++) {
//		if (i + v[i].first <= N) {
//			findAns(i + v[i].first, sum + v[i].second);
//		}
//		findAns(i + v[i].first, sum);
//	}
//}
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int y, x;
//		cin >> y >> x;
//		v.push_back(make_pair(y, x));
//	}
//	//answer
//	findAns(0, 0);
//	cout << maxProfit;
//}