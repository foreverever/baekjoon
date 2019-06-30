#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Country {
	int num, gold, silver, bronze;

	Country(int n, int g, int s, int b) {
		this->num = n;
		this->gold = g;
		this->silver = s;
		this->bronze = b;
	}
	Country() {}
};

int N, K;
vector<Country> v;

bool cmp(Country &first, Country &second) {
	if (first.gold == second.gold) {
		if (first.silver == second.silver) {
			return first.bronze > second.bronze;
		}
		return first.silver > second.silver;
	}
	return first.gold > second.gold;
}

void input() {
	int n, g, s, b;

	for (int i = 1; i <= N; i++) {
		cin >> n >> g >> s >> b;
		v.push_back(Country(n, g, s, b));
	}
}

bool isSame(Country &first, Country &second) {
	return (first.gold == second.gold
		&& first.silver == second.silver
		&& first.bronze == second.bronze);
}

int findAns() {
	sort(v.begin(), v.end(), cmp);

	int rank = 1, same = 1;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i].num == K) return rank;
		if (isSame(v[i], v[i + 1])) same++;
		else if (same > 1) {
			rank += same;
			same = 1;
		}
		else rank++;
	}
	return rank;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	input();
	cout << findAns();
	return 0;
}