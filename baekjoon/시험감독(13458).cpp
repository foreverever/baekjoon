#include <iostream>
typedef long long ll;
using namespace std;

int N, B, C;
int arr[1000001];
ll ans;

void findAns() {
	for (int i = 0; i < N; i++) {
		arr[i] -= B;
		ans++;
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] <= 0) continue;
		if (arr[i] % C != 0) {
			ans += arr[i] / C + 1;
			continue;
		}
		ans += arr[i] / C;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &B, &C);
	findAns();
	printf("%lld", ans);
	return 0;
}