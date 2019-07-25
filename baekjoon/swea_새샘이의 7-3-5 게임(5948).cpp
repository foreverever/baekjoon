#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;

int tc;
int arr[7];
bool visit[7];

void dfs(int idx, int cnt, int sum, set<int, greater<int> > &s) {
	if (cnt == 3) {
		s.insert(sum);
		return;
	}
	for (int cur = idx; cur < 7; cur++) {
		if (!visit[cur]) {
			visit[cur] = true;
			dfs(cur + 1, cnt + 1, sum + arr[cur], s);
			visit[cur] = false;
		}
	}
}

void findAns(int testCase) {
	set<int, greater<int> > s;
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < 7; i++) scanf("%d", &arr[i]);
	dfs(0, 0, 0, s);
	printf("#%d %d\n", testCase, *next(s.begin(), 4));
}

int main() {
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		findAns(t);
	}
	return 0;
}