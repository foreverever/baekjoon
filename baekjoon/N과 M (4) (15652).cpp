#include <iostream>
#include	<vector>

using namespace std;
int N, M;
vector<int> v;

void dfs(int cnt) {
	if (cnt == M) {
		for (int val : v) cout << val << ' ';
		cout << '\n';
		return;
	}

	for (int cur = 1; cur <= N; cur++) {
		if (v.empty() || v.back() <= cur) {
			v.push_back(cur);
			dfs(cnt + 1);
			v.pop_back();
		}
	}
}

void findAns() {
	dfs(0);
}

int main() {
	cin >> N >> M;
	findAns();
	return 0;
}