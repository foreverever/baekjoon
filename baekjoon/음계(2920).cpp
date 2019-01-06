#include <iostream>
#include <string>
using namespace std;

int x, y = 2e9, aCnt, bCnt;

string findAns() {
	if (aCnt == 7) return "ascending";
	if (bCnt == 7) return "descending";
	return "mixed";
}

int main() {
	for (int i = 0; i < 8; i++) {
		cin >> x;
		if (y + 1 == x) aCnt++;
		if (y - 1 == x) bCnt++;
		y = x;
	}
	cout << findAns();
	return 0;
}