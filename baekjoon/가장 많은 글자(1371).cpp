#include <iostream>
#include <string>
#include <map>
using namespace std;

string str;
map<char, int> m;
map<char, int>::iterator iter;

void checkAlphabet(string &str) {
	for (char c : str) m[c]++;
}

int findMaxNumber() {
	int mx = -2e9;

	for (iter = m.begin(); iter != m.end(); iter++) {
		if (mx < iter->second) {
			mx = iter->second;
		}
	}
	return mx;
}

string findMaxAlphabet(int mx) {
	string str = "";

	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == mx) {
			str += iter->first;
		}
	}
	return str;
}

string calcMax() {
	int mx = findMaxNumber();
	string ans = findMaxAlphabet(mx);
	
	return ans;
}

string findAns() {
	while (1) {
		cin >> str;
		if (cin.eof()) break;
		checkAlphabet(str);
	}
	return calcMax();
}

int main() {
	cout << findAns();
	return 0;
}