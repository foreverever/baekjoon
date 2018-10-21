//#include <iostream>
//#include <vector>
//#include <string.h>
//#define JANUARY 3
//#define DECEMBER 14
//using namespace std;
//int T;
//int dp[15];
//int plan[15];
//vector <int> fee;
//
//void findAns() {
//	for (int i = JANUARY; i <= DECEMBER; i++) {
//		if (plan[i] == 0) {
//			dp[i] = dp[i - 1];
//		}
//		if (plan[i] > 0) {
//			//1일 이용권
//			dp[i] = dp[i - 1] + plan[i] * fee[0];
//			//1달 이용권
//			if (dp[i] > dp[i - 1] + fee[1]) {
//				dp[i] = dp[i - 1] + fee[1];
//			}
//			//3달 이용권
//			if (dp[i] > dp[i - 3] + fee[2]) {
//				dp[i] = dp[i - 3] + fee[2];
//			}
//			//1년 이용권
//			if (dp[i] > fee[3]) {
//				dp[i] = fee[3];
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> T;
//	for (int t = 1; t <= T; t++) {
//		for (int i = 0; i < 4; i++) {
//			int input;
//			cin >> input;
//			fee.push_back(input);
//		}
//		for (int i = JANUARY; i <= DECEMBER; i++) {
//			cin >> plan[i];
//		}
//		findAns();
//		cout << "#" << t << ' ' << dp[DECEMBER] << '\n';
//		fee.clear();
//		memset(dp, 0, sizeof(dp));
//	}
//	return 0;
//}

///////////////////////////////////////////////////재귀이용//////////////////////////////////////////////////////
//#include <iostream>
//#include <vector>
//#define DAY 0
//#define ONE_M 1
//#define THREE_M 2
//#define YEAR 3
//#define JAN 0
//#define DEC 11
//using namespace std;
//int T;
//vector <int> fee;
//int plan[12];
//int ans = 2e9;
//
//void findAns(int month, int sum) {
//	if (month > DEC) {
//		ans = ans > sum ? sum : ans;
//		return;
//	}
//	if (plan[month] > 0) {
//		for (int i = DAY; i <= YEAR; i++) {
//			if (i == DAY) {
//				findAns(month + 1, sum + plan[month] * fee[DAY]);
//			}
//			if (i == ONE_M) {
//				findAns(month + 1, sum + fee[ONE_M]);
//			}
//			if (i == THREE_M) {
//				findAns(month + 3, sum + fee[THREE_M]);
//			}
//			if (i == YEAR) {
//				findAns(DEC + 1, fee[YEAR]);
//			}
//		}
//	}
//	else {
//		findAns(month + 1, sum);
//	}
//}
//
//int main() {
//	cin >> T;
//	for (int t = 1; t <= T; t++) {
//		for (int i = 0; i < 4; i++) {
//			int input;
//			cin >> input;
//			fee.push_back(input);
//		}
//		for (int i = JAN; i <= DEC; i++) {
//			cin >> plan[i];
//		}
//		findAns(JAN, 0);
//		cout << "#" << t << ' ' << ans << '\n';
//		fee.clear();
//		ans = 2e9;
//	}
//	return 0;
//}