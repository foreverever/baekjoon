#include <iostream>
#include <string>
#include <algorithm>
#define DIV 1000000007

typedef long long ll;
using namespace std;

int tc;

int calc(string s) {
	int cnt = 1;
	sort(s.begin(), s.end());

	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] != s[i + 1]) cnt++;
	}
	return cnt;
}

int findAns() {
	string str;
	ll ans = 1;
	cin >> str;

	if (str.size() == 1) return ans;
	if (str[0] != str[1]) ans *= 2;
	if (str[str.size() - 2] != str[str.size() - 1]) ans *= 2;

	string tmp;
	for (int i = 1; i < str.size() - 1; i++) {
		tmp = "";
		tmp += str[i - 1];
		tmp += str[i];
		tmp += str[i + 1];
		ans *= calc(tmp);
		ans %= DIV;
	}
	return ans;
}

int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		printf("#%d %d\n", t, findAns());
	}
	return 0;
}