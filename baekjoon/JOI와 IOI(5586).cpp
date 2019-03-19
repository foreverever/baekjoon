#include <iostream>
#include <string>

using namespace std;
string str, tmp;
int first, second;

void findAns() {
	for (int i = 0; i < str.size() - 2; i++) {
		if (str[i] == 'J') {
			tmp = str.substr(i, 3);
			if (tmp == "JOI") first++;
		}
		else if (str[i] == 'I') {
			tmp = str.substr(i, 3);
			if (tmp == "IOI") second++;
		}
	}
}

int main() {
	cin >> str;
	findAns();
	cout << first << '\n' << second;
	return 0;
}