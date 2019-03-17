#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<int, int> m;

int main() {
	scanf("%d", &N);
	int x;
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		m[x]++;
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &x);
		printf("%d ", m[x]);
	}
	return 0;
}