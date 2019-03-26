#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> big[100];
vector<int> small[100];
bool used[100][100];
int total[100];
int N, M, ans;

void bigDfs(int i, int cur) {
	for (int j = 0; j < big[cur].size(); j++) {
		if (used[i][big[cur][j]] == false) {
			used[i][big[cur][j]] = true;
			total[i]++;
			bigDfs(i,big[cur][j]);
		}
	}
}

void smallDfs(int i, int cur) {
	for (int j = 0; j < small[cur].size(); j++) {
		if (used[i][small[cur][j]] == false) {
			used[i][small[cur][j]] = true;
			total[i]++;
			smallDfs(i, small[cur][j]);
		}
	}
}

void findAns() {
	int range = N / 2;

	for (int i = 1; i <= N; i++) {
		bigDfs(i, i);
	}
	for (int i = 1; i <= N; i++) {
		if (total[i] > range) ans++;
	}

	memset(used, false, sizeof(used));
	memset(total, 0, sizeof(total));

	for (int i = 1; i <= N; i++) {
		smallDfs(i, i);
	}
	for (int i = 1; i <= N; i++) {
		if (total[i] > range) ans++;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	int s, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &b);
		big[s].push_back(b);
		small[b].push_back(s);
	}
	findAns();
	printf("%d", ans);
	return 0;
}