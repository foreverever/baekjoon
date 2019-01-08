#include <iostream>
#include <string>
using namespace std;
int tc, n;
string str;

void findAns() {
	for (char var : str) {
		for (int i = 0; i < n; i++) {
			cout << var;
		}
	}
	cout << '\n';
}
int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> str;
		findAns();
	}
	return 0;
}