#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
string first, second;
int minVal, maxVal;

void findAns(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '6') str[i] = '5';
	}
	minVal += atoi(str.c_str());

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '5') str[i] = '6';
	}
	maxVal += atoi(str.c_str());
}

int main() {
	cin >> first >> second;
	findAns(first);
	findAns(second);
	cout << minVal << ' ' << maxVal;
	return 0;
}