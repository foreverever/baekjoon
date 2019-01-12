#include <iostream>
#include <map>
#include <string>

using namespace std;
map<char, bool> m;

string str, cambridge = "CAMBRIDGE";

void findAns() {
	for (char var : cambridge) {
		m[var] = true;
	}
	for (char var : str) {
		if (!m[var]) cout << var;
	}
}

int main() {
	cin >> str;
	findAns();
	return 0;
}