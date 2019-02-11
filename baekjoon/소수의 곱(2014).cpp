#include <iostream>
#include <set>
#include <vector>

using namespace std;

int k, n;
long long maxVal = 2e10;
set<long long> s;
vector<int> prime;

void input() {
	int input = 0;
	for (int i = 0; i < k; i++) {
		cin >> input;
		prime.push_back(input);
		s.insert(input);
	}
}

int findAns() {
	set<long long>::iterator iter;
	int cnt = 0;
	long long next = 0;
	for (iter = s.begin(); iter != s.end(); iter++) {
		for (int i = 0; i < prime.size(); i++) {
			if (s.size() == n) {
				maxVal = *(--s.end());
			}
			next = *iter*prime[i];
			if (maxVal > next) {
				s.insert(next);
			}
		}
		cnt++;
		if (cnt == n) return *iter;
	}
}

int main() {
	cin >> k >> n;
	input();
	cout << findAns();
	return 0;
}