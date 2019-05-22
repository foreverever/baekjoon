#include <iostream>
using namespace std;

int tc, n;

int findAns() {
	cin >> n;
	int total = 1;
	for (int i = 1; i < n; i++) {
		total = (total + 0.5) * 2;
	}
	return total;
}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << findAns() << '\n';
	}
	return 0;
}