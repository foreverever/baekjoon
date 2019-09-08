#include <iostream>

typedef long long ll;
using namespace std;

int N;
ll arr[51];

void input() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
}

bool isDiff() {
	return arr[N - 1] - arr[N - 2] == arr[N - 2] - arr[N - 3];
}

int findAns() {
	if (isDiff()) return 2 * arr[N - 1] - arr[N - 2];
	return arr[N - 1] * arr[N - 1] / arr[N - 2];
}

int main() {
	input();
	printf("%d", findAns());
	return 0;
}