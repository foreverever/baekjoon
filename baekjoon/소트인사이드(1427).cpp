#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;

bool cmp(char &c1, char &c2) {
	return c1 > c2;
}

int main() {
	cin >> s;
	sort(s.begin(), s.end(), cmp);
	cout << s;
	return 0;
}