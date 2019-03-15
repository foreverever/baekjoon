#include <iostream>
#include <map>
using namespace std;

int N, M, x;
map<int, int> m;

void findAns() {
	for (int i = 0; i < M; i++) {
		scanf("%d", &x);
		if (m.count(x)) printf("1 ");
		else printf("0 ");
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		m[x] = 1;
	}
	scanf("%d", &M);
	findAns();
	return 0;
}