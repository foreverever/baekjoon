#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
string str;
vector<string> ans;

void findAns() {
	for (int i = 0; i < str.size(); i++) {
		ans.push_back(str.substr(i));
	}
	sort(ans.begin(), ans.end());

	for (string s : ans) {
		cout << s << '\n';
	}
}

int main() {
	cin >> str;
	findAns();
	return 0;
}
