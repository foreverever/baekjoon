#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector <string> str;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string c;
		cin >> c;
		str.push_back(c);
	}
}

string findAns() {
	string ans, str1, str2;
	ans = str1 = str2 = str[0];
	for (int i = 1; i < str.size(); i++) {
		str1 = ans + str[i];
		str2 = str[i] + ans;
		if (str1 < str2) {
			ans = str2;
		}
		else {
			ans = str1;
		}
	}
	str.clear();
	return ans;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		cout << '#' << t << ' ' << findAns() << '\n';
	}
	return 0;
}