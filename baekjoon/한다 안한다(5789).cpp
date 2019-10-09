#include <iostream>
#include <string>
#define DO "Do-it"
#define DO_NOT "Do-it-Not"
using namespace std;

int T;

string findAns(string str) {
	int idx = str.size() / 2;

	if (str[idx] == str[idx - 1]) return DO;
	return DO_NOT;
}

int main() {
	cin >> T;

	string input;
	for (int tc = 1; tc <= T; tc++) {
		cin >> input;
		cout << findAns(input) << '\n';
	}
	return 0;
}