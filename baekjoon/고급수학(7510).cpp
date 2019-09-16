#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define SC "Scenario"
#define YES "yes"
#define NO "no"
typedef long long ll;

using namespace std;

int tc;

string findAns() {
	ll x;
	vector<ll> v;

	for (int i = 0; i < 3; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	ll smallSum = v[0] * v[0] + v[1] * v[1];
	ll bigSum = v[2] * v[2];

	return smallSum == bigSum ? YES : NO;
}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << SC << " #" << t << ":" << '\n' << findAns() << '\n' << '\n';
	}
	return 0;
}