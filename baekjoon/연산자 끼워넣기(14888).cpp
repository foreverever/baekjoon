#include <iostream>
#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3

using namespace std;

int N, arr[12], op[4];
int mn = 2e9, mx = -2e9;

void dfs(int idx, int result) {
	if (idx == N) {
		mn = mn > result ? result : mn;
		mx = mx < result ? result : mx;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) continue;
		if (i == PLUS) {
			op[i]--;
			dfs(idx + 1, result + arr[idx]);
			op[i]++;
		}
		else if (i == MINUS) {
			op[i]--;
			dfs(idx + 1, result - arr[idx]);
			op[i]++;
		}
		else if (i == MUL) {
			op[i]--;
			dfs(idx + 1, result * arr[idx]);
			op[i]++;
		}
		else if (i == DIV) {
			op[i]--;
			dfs(idx + 1, result / arr[idx]);
			op[i]++;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}
	dfs(1, arr[0]);
	printf("%d\n%d", mx, mn);
	return 0;
}