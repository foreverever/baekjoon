#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
map<char, int> m;
vector<int> v;

void input() {
	int x;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
}

void findAns() {
	for (char i = 'C'; i >= 'A'; i--) {
		m[i] = v.back();
		v.pop_back();
	}
	char c;
	for (int i = 0; i < 3; i++) {
		cin >> c;
		cout << m[c] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(false);
	input();
	findAns();
	return 0;
}