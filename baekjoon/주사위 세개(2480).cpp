#include <iostream>
using namespace std;

int arr[7];

void input() {
	int x;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		arr[x]++;
	}
}

int findAns() {
	int mx = -2e9, ans[4];

	for (int i = 1; i <= 6; i++) {
		if (arr[i] != 0 && mx <= arr[i]) {
			mx = arr[i];
			ans[mx] = i;
		}
	}

	if (mx == 1) return ans[mx] * 100;
	if (mx == 2) return 1000 + ans[mx] * 100;
	return 10000 + ans[mx] * 1000;
}

int main() {
	input();
	cout << findAns();
	return 0;
}