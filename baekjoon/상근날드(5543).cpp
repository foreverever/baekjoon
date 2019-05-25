#include <iostream>
#define MAX 5
using namespace std;

int findAns() {
	int hamburger = 2e9, beverage = 2e9;
	int n = 0;

	for (int i = 1; i <= MAX; i++) {
		cin >> n;
		if (i <= 3) hamburger = hamburger > n ? n : hamburger;
		else beverage = beverage > n ? n : beverage;
	}
	return hamburger + beverage - 50;
}

int main() {
	cout << findAns();
	return 0;
}