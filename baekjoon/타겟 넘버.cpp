#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int ans;

void dfs(int idx, int sum, int target) {
	if (idx == v.size()) {
		if (sum == target) ans++;
		return;
	}
	dfs(idx + 1, sum - v[idx], target);
	dfs(idx + 1, sum + v[idx], target);
}

int solution(vector<int> numbers, int target) {
	v = numbers;
	dfs(0, 0, target);
	return ans;
}