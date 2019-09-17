#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
bool used[9];
vector<int> v;

void dfs(int cnt) {
	if (cnt == M) {
		for (int val : v) cout << val << ' ';
		cout << '\n';
		return;
	}
	for (int cur = 0; cur < N; cur++) {
		if (!used[cur]) {
			used[cur] = true;
			v.push_back(arr[cur]);
			dfs(cnt + 1);
			v.pop_back();
			used[cur] = false;
		}
	}
}

void findAns() {
	sort(arr, arr + N);
	dfs(0);
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	input();
	findAns();
	return 0;
}