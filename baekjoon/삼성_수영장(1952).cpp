#include <iostream>
#include <vector>
#include <string.h>
#define JANUARY 3
#define DECEMBER 14
using namespace std;
int T;
int dp[15];
int plan[15];
vector <int> fee;

void findAns() {
	for (int i = JANUARY; i <= DECEMBER; i++) {
		if (plan[i] == 0) {
			dp[i] = dp[i - 1];
		}
		if (plan[i] > 0) {
			//1일 이용권
			dp[i] = dp[i - 1] + plan[i] * fee[0];
			//1달 이용권
			if (dp[i] > dp[i - 1] + fee[1]) {
				dp[i] = dp[i - 1] + fee[1];
			}
			//3달 이용권
			if (dp[i] > dp[i - 3] + fee[2]) {
				dp[i] = dp[i - 3] + fee[2];
			}
			//1년 이용권
			if (dp[i] > fee[3]) {
				dp[i] = fee[3];
			}
		}
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++) {
			int input;
			cin >> input;
			fee.push_back(input);
		}
		for (int i = JANUARY; i <= DECEMBER; i++) {
			cin >> plan[i];
		}
		findAns();
		cout << "#" << t << ' ' << dp[DECEMBER] << '\n';
		fee.clear();
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}