#include <iostream>
#include <algorithm>

using namespace std;
int M, N, ans= 2e9+1;
int arr[100001];

int findAns() {
	int s = 0, e = 1;
	while (s < N) {
		if (arr[e] - arr[s] < M) {
			e++;
			continue;
		}
		if (arr[e] - arr[s] == M) {
			return M;
		}
		ans = min(ans, arr[e] - arr[s]);
		s++;
	}
	return ans;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	printf("%d", findAns());
	return 0;
}