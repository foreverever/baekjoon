#include <iostream>
#include <string>

using namespace std;
string str;
int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if ((i +1) % 10 == 0) {
			cout << str[i] << '\n';
		}
		else {
			cout << str[i];
		}
	}
	return 0;
}