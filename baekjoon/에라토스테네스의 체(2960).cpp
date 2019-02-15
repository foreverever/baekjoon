#include <iostream>
#include <map>
#include<vector>

using namespace std;

int N, K;
map<int, bool> m;
map<int, bool>::iterator iter;
vector<int> ans;

bool isPrime(int n) {
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (n%i == 0) cnt++;
	}
	return cnt == 1;
}

void erase(int n) {
	for (int i = 1; i*n <= N; i++) {
		if (m[i*n] == false) {
			m[i*n] = true;
			ans.push_back(i*n);
		}
	}
}

void findAns() {
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (isPrime(iter->first) && iter->second == false) {
			erase(iter->first);
		}
	}
}

int main() {
	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		m[i] = false;
	}
	findAns();
	cout << ans[K - 1];
	return 0;
}