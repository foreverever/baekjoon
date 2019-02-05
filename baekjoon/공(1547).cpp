#include <iostream>

using namespace std;
int x, y, n, ans = 1;

void findAns() {
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x == ans) {
			ans = y;
		}
		else if (y == ans) {
			ans = x;
		}
	}
}

int main() {
	cin >> n;
	findAns();
	cout << ans;
	return 0;
}