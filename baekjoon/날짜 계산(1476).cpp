#include <iostream>
using namespace std;

int E, S, M;

void calc(int &p, int range) {
	if (p + 1 > range) p = 1;
	else p++;
}

int findAns() {
	int cnt = 1, e = 1, s = 1, m = 1;

	while (1) {
		if (E == e && S == s && M == m) return cnt;
		calc(e, 15);
		calc(s, 28);
		calc(m, 19);
		cnt++;
	}
}

int main() {
	cin >> E >> S >> M;
	cout << findAns();
	return 0;
}