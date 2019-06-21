#include <iostream>
#include <vector>
#include <string>
#include <math.h>
typedef long long ll;
using namespace std;

ll N, mn = 2e10, mx = -2e10;
vector<ll> v = { 0,1,2,3,4,5,6,7,8,9 };
vector<ll> n;
bool visit[10];
char sign[9];

void dfs(int cnt, int first, int second) {
	if (cnt >= 2) {
		if (sign[cnt - 2] == '<') {
			if (first > second) return;
		}
		else if (sign[cnt - 2] == '>') {
			if (first < second) return;
		}
	}
	if (cnt == N + 1) {
		ll num = 0;
		for (int i = 0; i < n.size(); i++) {
			num += n[i] * pow(10, n.size() - i - 1);
		}

		mx = mx < num ? num : mx;
		mn = mn > num ? num : mn;
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (visit[i] == false) {
			visit[i] = true;
			n.push_back(v[i]);
			dfs(cnt + 1, second, v[i]);
			visit[i] = false;
			n.pop_back();
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sign[i];
	}
}

void findAns() {
	for (int i = 0; i < v.size(); i++) {
		if (visit[i] == false) {
			visit[i] = true;
			n.push_back(v[i]);
			dfs(1, 0, v[i]);
			visit[i] = false;
			n.pop_back();
		}
	}
}

string toString(ll num) {
	string n = to_string(num);

	if (n.size() < N + 1) {
		n = '0';
		n += to_string(num);
	}
	return n;
}

int main() {
	input();
	findAns();
	cout << toString(mx) << '\n' << toString(mn);
	return 0;
}