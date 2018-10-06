//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define FINISH 6
//#define MAX 13
//using namespace std;
//
//int N = 1;
//vector<int> s, ans, temp;
//bool check[MAX];
//
//void dfs(int cnt) {
//	if (cnt == FINISH) {
//		temp.clear();
//		for (int i = 0; i < FINISH; i++) {
//			temp.push_back(ans[i]);
//		}
//		sort(temp.begin(), temp.end());
//		for (int i = 0; i < FINISH; i++) {
//			if (temp[i] != ans[i]) {
//				return;
//			}
//		}
//		for (int i = 0; i < FINISH; i++) {
//			cout << ans[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//	for (int i = 0; i < N; i++) {
//		if (check[i] == false) {
//			check[i] = true;
//			ans.push_back(s[i]);
//			dfs(cnt + 1);
//			ans.pop_back();
//			check[i] = false;
//		}
//	}
//}
//
//int main() {
//	while (N) {
//		cin >> N;
//		for (int i = 0; i < N; i++) {
//			int input;
//			cin >> input;
//			s.push_back(input);
//		}
//		dfs(0);
//		cout << '\n';
//		s.clear();
//		ans.clear();
//	}
//	return 0;
//}