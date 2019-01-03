#include <iostream>
#include <map>
#include <string>

using namespace std;
string s;
map <char, int> alph;

void initMap() {
	for (char c = 'a'; c <= 'z'; c++) {
		alph[c] = 0;
	}
}

void findAns() {
	for (int i = 0; i < s.size(); i++) {
		alph[s[i]]++;
	}
	map<char, int>::iterator iter;
	for (iter = alph.begin(); iter != alph.end(); iter++) {
		cout << iter->second << ' ';
	}
}

int main() {
	cin >> s;
	initMap();
	findAns();
	return 0;
}