#include <iostream>
using namespace std;

int tc, leg, n;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> leg >> n;
		int nn = n * 2;
		cout << nn - leg << ' ' << n - (nn - leg) << '\n';
	}
	return 0;
}