#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> prime;
bool used[1001];
int n, ans;

void erase(int v) {
	for (int i = v; i <= n; i += v) {
		if (used[i] == false) used[i] = true;
	}
}

void initPrime() {
	for (int i = 2; i <= n; i++) {
		if (used[i] == false) {
			prime.push_back(i);
			erase(i);
		}
	}
	memset(used, false, sizeof(used));
}

void calc(int cnt, int sum, int idx) {
	if (cnt == 3) {
		if (sum == n) { 
			ans++;
			for (int i = 0; i <= n; i++) {
				if (used[i] == true) cout << prime[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	for (int i = idx; i < prime.size(); i++) {
		if (used[i] == false) {
			used[i] = true;
			calc(cnt + 1, sum + prime[i], i);
			used[i] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	initPrime();
	calc(0, 0, 0);
	printf("%d", ans);
	return 0;
}