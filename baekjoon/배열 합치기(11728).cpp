#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

void findAns() {
	ios_base::sync_with_stdio(false);
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < M; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
}

int main() {
	cin >> N >> M;
	findAns();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	return 0;
}