#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
string a, b;

void input() {
	string x = "";
	for (int i = 0; i < 2; i++) {
		cin >> x;
		a += x;
	}
	for (int i = 0; i < 2; i++) {
		cin >> x;
		b += x;
	}
}

void findAns() {
	cout << atoll(a.c_str()) + atoll(b.c_str());
}

int main() {
	input();
	findAns();
	return 0;
}