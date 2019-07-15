#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string str;
unordered_map<char, bool> m;
char vowel[5] = { 'a','e', 'i', 'o', 'u' };

void input() {
	getline(cin, str);
}

void initVowel() {
	for (char c : vowel) m[c] = true;
}

string findAns() {
	initVowel();

	string ans = "";
	int size = str.size();

	for (int i = 0; i < size; i++) {
		if (m.count(str[i])) {
			ans += str[i];
			i += 2;
			continue;
		}
		ans += str[i];
	}
	return ans;
}

int main() {
	input();
	cout << findAns();
	return 0;
}