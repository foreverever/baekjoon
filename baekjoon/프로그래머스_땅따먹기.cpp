#include <iostream>
#include <vector>
using namespace std;

int dp[100001][4];

int findMax(int line[4], int cur) {
	int mx = -2e9;
	for (int i = 0; i < 4; i++) {
		if (i == cur) continue;
		if (mx < line[i]) mx = line[i];
	}
	return mx;
}

int solution(vector<vector<int> > land) {
	int answer = 0;

	for (int i = 0; i < 4; i++) dp[0][i] = land[0][i];	//첫 행 초기화

	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < 4; j++) {
			dp[i][j] = findMax(dp[i - 1], j) + land[i][j];
		}
	}
	return findMax(dp[land.size() - 1], -1);
}

//dp문제로서, 점화식을 세우도록 한다.
//먼저 dp[i][j]는 i행j번째 까지 최대값을 의미하도록 이차원 배열로 정의했다. 즉, dp[i]는 i번째 행 까지의 최대값 배열이 된다.
//점화식은 'dp[i][j] = max(dp[i-1][0], dp[i-1][1] ..) + land[i][j]' 로 만들었다.
//이때 주의할점은, 이웃한 행에 대해서 같은 열은 제외해야 하므로 점화식의 max인자로 j번째 최대값인 dp[i][j]는 제외하도록 한다.
//범위 내의 dp배열을 다 구한후, dp배열의 마지막 행에서 가장 큰 열의 값이 구하고자 하는 최대값이 된다.