#include <iostream>

using namespace std;

int N, ans;
int main() {
	scanf("%d", &N);
	int K = 1;
	while (N) {
		if (N >= K) {
			N -= K++;
			ans++;
		}
		else K = 1;
	}
	printf("%d", ans);
	return 0;
}