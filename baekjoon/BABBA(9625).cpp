#include <iostream>
using namespace std;

int N;
int ans[46];

void fib() {
	ans[1] = 1; ans[2] = 1;
	for (int i = 3; i <= N; i++) {
		ans[i] = ans[i - 1] + ans[i - 2];
	}
}

int main() {
	scanf("%d", &N);
	fib();
	printf("%d %d", ans[N - 1], ans[N]);
	return 0;
}