#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string str;
unordered_map<char, int> m;
char cardShap[4] = { 'P', 'K', 'H', 'T' };

bool isDuplicate() {
	unordered_map<string, bool> check;
	string tmp = "";
	bool result = false;

	for (int i = 0; i < str.size(); i += 3) {
		tmp = str.substr(i, 3);
		m[str[i]]--;
		if (check.count(tmp) && !result) result = true;
		else check[tmp] = true;
	}
	return result;
}

void initCard() {
	for (char c : cardShap) m[c] = 13;
}

void findAns() {
	initCard();

	if (isDuplicate()) {
		cout << "GRESKA";
		return;
	}
	for (char c : cardShap) cout << m[c] << ' ';
}

int main() {
	cin >> str;
	findAns();
	return 0;
}