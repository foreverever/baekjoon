//#include <iostream>
//#include <utility>
//#include <vector>
//using namespace std;
//
//int N;
//vector<pair<pair<int, int>, int > > v;
//
//int main() {
//	cin >> N;
//	int y, x;
//	for (int i = 0; i < N; i++) {
//		cin >> y >> x;
//		v.push_back(make_pair(make_pair(y, x), 1));
//	}
//	//asnwer
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (i == j) {
//				continue;
//			}
//			//i번째 덩치가 더 작은 경우
//			if (v[i].first.first < v[j].first.first && v[i].first.second < v[j].first.second) {
//				v[i].second++;
//			}
//		}
//	}
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i].second << ' ';
//	}
//	return 0;
//}