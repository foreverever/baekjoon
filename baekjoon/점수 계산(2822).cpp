#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
vector<pair<int, int> > v;
vector<int> num;
int sum;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
	return p1.second > p2.second;
}

void findAns() {
	int x;
	for (int i = 0; i < 8; i++) {
		cin >> x;
		v.push_back({ i + 1,x });
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < 5; i++) {
		sum += v[i].second;
		num.push_back(v[i].first);
	}
	sort(num.begin(), num.end());
}

void output() {
	cout << sum << '\n';
	for (int val : num) {
		cout << val << ' ';
	}
}

int main() {
	findAns();
	output();
	return 0;
}