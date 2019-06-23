#include <iostream>
#include <math.h>

using namespace std;

struct Ans {
	int sum = 0, mn = 0;
	bool isExist = false;
};

int start, back;

Ans findAns() {
	Ans ans;
	int nStart = sqrt(start);
	int nBack = sqrt(back);

	for (int i = nStart; i <= nBack; i++) {
		int cur = pow(i, 2);
		if (cur >= start && cur <= back) {
			if (!ans.isExist) {
				ans.mn = cur;
				ans.isExist = true;
			}
			ans.sum += cur;
		}
	}
	return ans;
}

int main() {
	cin >> start >> back;
	Ans ans = findAns();

	if (ans.isExist) cout << ans.sum << '\n' << ans.mn;
	else cout << -1;
	return 0;
}