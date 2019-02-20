#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
int dp[301];

void findAns() {
	int x;
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		v.push_back(x);
	}
	dp[0] = 0;
	dp[1] = v[1];
	dp[2] = dp[1] + v[2];
	for (int i = 3; i <= N; i++) {
		int one = v[i] + dp[i - 2];
		int two = v[i] + v[i - 1] + dp[i - 3];
		dp[i] = one > two ? one : two;
	}
	cout << dp[N];
}

int main() {
	scanf("%d", &N);
	findAns();
	return 0;
}