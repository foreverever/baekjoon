#include <iostream>
#include <vector>

using namespace std;

int N;
bool isNotPrime[4000001];
vector<int> prime;

void erase(int num) {
	for (int i = num; i <= N; i += num) isNotPrime[i] = true;
}

void getPrime() {
	for (int i = 2; i <= N; i++) {
		if (!isNotPrime[i]) {
			erase(i);
			prime.push_back(i);
		}
	}
}

void output() {
	for (int val : prime) cout << val << ' ';
}

int findAns() {
	int cnt = 0, s = 0, e = 0, sum = 0;
	int range = prime.size();

	while (s <= e) {
		if (sum == N) {
			cnt++;
			sum -= prime[s++];
			continue;
		}
		if (sum > N) {
			sum -= prime[s++];
			continue;
		}
		if (e == range) return cnt;
		if (sum < N) sum += prime[e++];
	}
	return cnt;
}

int main() {
	cin >> N;
	getPrime();
	cout << findAns();
	return 0;
}