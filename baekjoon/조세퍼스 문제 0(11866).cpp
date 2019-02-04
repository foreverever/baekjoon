//나머지 연산 사용 (12ms)
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, M;
vector<pair<int, bool> > v;
vector<int> ans;
int cnt, current;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		v.push_back({ i,false });
	}
}

void deleteNum(int current) {
	ans.push_back(v[current].first + 1);
	v[current].second = true;
	cnt = 0;
}

void findAns() {
	for (int i = 0; ans.size() != N; i++) {
		current = i % N;
		if (v[current].second) continue;
		cnt++;
		if (cnt != M) continue;
		deleteNum(current);
	}
}

void output() {
	cout << '<';
	for (int i = 0; i < ans.size(); i++) {
		if (i == ans.size() - 1) cout << ans[i] << '>';
		else cout << ans[i] << ", ";
	}
}

int main() {
	input();
	findAns();
	output();
	return 0;
}

//큐 사용 (0ms)
#include <iostream>
#include <queue>
using namespace std;

int N, M;
queue<int> q;

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
}

void findAns() {
	cout << '<';
	while (!q.empty()) {
		for (int i = 1; i < M; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty()) cout << ", ";
	}
	cout << '>';
}

int main() {
	input();
	findAns();
	return 0;
}