#include <iostream>
#include <string>
using namespace std;

string str;

int findAns() {
	string tmp = "";
	int ans = 0;

	for (char c : str) {
		if (c == ',') {
			ans+= atoi(tmp.c_str());
			tmp = "";
			continue;
		}
		tmp += c;
	}
	ans += atoi(tmp.c_str());
	return ans;
}

int main() {
	cin >> str;
	cout << findAns();
	return 0;
}