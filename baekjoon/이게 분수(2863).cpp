#include <iostream>

using namespace std;
int arr[2][2];

void input() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}
}

void rotation() {
	int tmp = arr[0][0];
	arr[0][0] = arr[1][0];
	arr[1][0] = arr[1][1];
	arr[1][1] = arr[0][1];
	arr[0][1] = tmp;
}

int findAns() {
	int n = 1, ans;
	double mx = -2e9, val;

	while (n <= 4) {
		rotation();
		val = ((double)arr[0][0] / arr[1][0]) + ((double)arr[0][1] / arr[1][1]);
		if (mx < val) {
			mx = val; ans = n;
		}
		n++;
	}
	return ans % 4;
}

int main() {
	input();
	cout << findAns();
	return 0;
}