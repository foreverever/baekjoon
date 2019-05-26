#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int n, m;
int cost[MAX], vote[MAX];

void initCost() {
	int input = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input);
		cost[i] = input;
	}
}

int findAns() {
	int input = 0, ans = 0;

	for (int i = 0; i < m; i++) {
		scanf("%d", &input);
		for (int j = 1; j <= n; j++) {
			if (cost[j] <= input) {
				vote[j]++;
				break;
			}
		}
	}
	int mx = -2e9;

	for (int i = 1; i <= n; i++) {
		if (mx < vote[i]) {
			mx = vote[i];
			ans = i;
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	initCost();
	printf("%d", findAns());
	return 0;
}