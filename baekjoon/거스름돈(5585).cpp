#include <iostream>
#define PAY 1000
using namespace std;

int n;

int findAns(int change) {
	int cnt = 0;
	if (change > 500) {
		change -= 500;
		cnt++;
	}
	while (change >= 100) {
		change -= 100;
		cnt++;
	}
	while (change >= 50) {
		change -= 50;
		cnt++;
	}
	while (change >= 10) {
		change -= 10;
		cnt++;
	}
	while (change >= 5) {
		change -= 5;
		cnt++;
	}
	if (change >= 1) cnt += change;
	return cnt;
}

int main() {
	cin >> n;
	cout << findAns(PAY - n);
	return 0;
}