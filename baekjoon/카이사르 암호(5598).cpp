#include <iostream>
#include <string>

using namespace std;

string str;
int main() {
	cin >> str;
	for (char s : str) {
		if (s < 'D') {
			cout << char('Z' - ('C'-s));
		}

		else {
			cout << char(s - 3);
		}
	}
	return 0;
}