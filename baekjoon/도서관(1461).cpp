#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <stack>

using namespace std;
int N, M;
int ans, maxVal;
vector <int> v;
queue <int> q;
stack <int> s;

void input() {
	cin >> N >> M;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
}

void findAns() {
	sort(v.begin(), v.end());
	maxVal = abs(v.front()) > abs(v.back()) ? abs(v.front()) : abs(v.back());

	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 0) {
			q.push(abs(v[i]));
		}
		if (v[i] > 0) {
			s.push(v[i]);
		}
	}
	while (!q.empty()) {
		ans += q.front() * 2;
		for (int i = 0; i < M; i++) {
			q.pop();
			if (q.empty()) break;
		}
	}
	while (!s.empty()) {
		ans += s.top() * 2;
		for (int i = 0; i < M; i++) {
			s.pop();
			if (s.empty()) break;
		}
	}
}

int main() {
	input();
	findAns();
	cout << ans-maxVal;
	return 0;
}