#include <iostream>
using namespace std;

int n, m;
int v[1000001];

int find(int a) {
	if (v[a] == a) return a;
	return v[a] = find(v[a]);
}

void uni(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);
	v[aRoot] = bRoot;
}

void findAns() {
	int x, a, b;
	for (int i = 1; i <= n; i++) {
		v[i] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &a, &b);
		if (x == 0) {
			uni(a, b);
		}
		else {
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	findAns();
	return 0;
}