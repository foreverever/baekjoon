#include <iostream>
#include <map>
#include <string>
using namespace std;
int N, ans;
string str;

void findAns() {
	char beforeValue = ' ';
	map <char, bool> m;
	bool isGropWord = true;
	for (int i = 0; i < str.size(); i++) {
		if (beforeValue == str[i]) continue;
		if (m[str[i]]) {
			isGropWord = false;
		}
		beforeValue = str[i];
		m[str[i]] = true;
	}
	if (isGropWord) ans++;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		findAns();
	}
	cout << ans;
	return 0;
}