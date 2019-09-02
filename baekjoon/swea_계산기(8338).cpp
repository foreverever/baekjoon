#include <iostream>

using namespace std;
int tc, N, mx;
int number[10];

void input() {
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
	}
	mx = number[0];
}

void dfs(int idx, int sum) {
	if (idx == N) {
		mx = mx < sum ? sum : mx;
		return;
	}
	dfs(idx + 1, sum + number[idx]);
	dfs(idx + 1, sum*number[idx]);
}

void findAns() {
	input();
	if (N == 1) return;
	dfs(1, number[0]);
}

int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &N);
		findAns();
		printf("#%d %d\n", t, mx);
	}
	return 0;
}