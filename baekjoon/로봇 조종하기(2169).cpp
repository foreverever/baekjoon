#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001][1001], dp[1001][1001], temp[2][1001];
int N, M;

void findAns() {
	//테두리 작업
	dp[0][0] = arr[0][0];
	for (int i = 1; i < M; i++) dp[0][i] = arr[0][i] + dp[0][i - 1];

	for (int i = 1; i < N; i++) {
		//왼쪽 mx
		temp[0][0] = dp[i - 1][0] + arr[i][0];
		for (int j = 1; j < M; j++) {
			temp[0][j] = arr[i][j] + max(temp[0][j - 1], dp[i - 1][j]);
		}
		//오른쪽 mx
		temp[1][M - 1] = dp[i - 1][M - 1] + arr[i][M - 1];
		for (int j = M - 2; j >= 0; j--) {
			temp[1][j] = arr[i][j] + max(temp[1][j + 1], dp[i - 1][j]);
		}
		//총 mx
		for (int j = 0; j < M; j++) {
			dp[i][j] = max(temp[0][j], temp[1][j]);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	findAns();
	printf("%d", dp[N - 1][M - 1]);
	return 0;
}