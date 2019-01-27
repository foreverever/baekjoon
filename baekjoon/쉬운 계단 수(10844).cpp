#include <iostream>
using namespace std;
long long dp[101][10];
long long ans;
long long divi = 1000000000;
int n;

void findAns() {
	for (int j = 1; j <= 9; j++) dp[1][j] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else if (j > 0 && j < 9)
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= divi;
		}
	}
	for (int i = 0; i <= 9; i++)
		ans += dp[n][i];
}

int main() {
	cin >> n;
	findAns();
	cout << ans % divi;
	return 0;
}