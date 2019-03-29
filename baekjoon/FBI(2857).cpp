#include <iostream>
#include <string>
#include <vector>

using namespace std;
string str;
vector<int> ans;

void findAns() {
	if (ans.empty()) {
		cout << "HE GOT AWAY!";
		return;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}

int main() {
	for (int i = 1; i <= 5; i++) {
		cin >> str;
		if (str.find("FBI") != string::npos) ans.push_back(i);
	}
	findAns();
	return 0;
}