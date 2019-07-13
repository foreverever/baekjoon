#include <iostream>
#include <string>

using namespace std;

int N;

string findTypo(int idx, string &str) {
	string tmp = "";

	for (int i = 0; i < str.size(); i++) {
		if (i == idx) continue;
		tmp += str[i];
	}
	return tmp;
}

void findAns() {
	int x;
	string str;

	for (int i = 0; i < N; i++) {
		cin >> x >> str;
		cout << findTypo(x-1, str) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	findAns();
	return 0;
}