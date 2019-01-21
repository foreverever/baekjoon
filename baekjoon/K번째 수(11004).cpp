#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> v;

void findAns() {
	sort(v.begin(), v.end());
	cout << v[K-1];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> K;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	findAns();
	return 0;
}