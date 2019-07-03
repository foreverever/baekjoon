#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

string s;
unordered_map<char, bool> vowels;
char v[5] = { 'a','e','i','o','u' };

void initVowels() {
	for (char c : v) vowels[c] = true;
}

int calc(string &s) {
	int cnt = 0;

	for (char c : s) {
		if (vowels.count(c)) cnt++;
	}
	return cnt;
}

void findAns() {
	initVowels();

	while (1) {
		getline(cin, s);
		if (s == "#") return;

		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << calc(s) << '\n';
	}
}

int main() {
	findAns();
	return 0;
}