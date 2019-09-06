#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
unordered_map<char, int> m;

void init() {
	for (char c = 'a'; c <= 'z'; c++) {
		m[c] = 1;
	}
}

int calc(string &str) {
	int sum = 0;
	for (char c : str) {
		if (m.count(c) && m[c] == 1) {
			sum++;
			m[c]++;
		}
	}
	return sum;
}

void findAns() {
	string input;
	while (1) {
		getline(cin, input);
		if (input == "#") return;
		init();
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		printf("%d\n", calc(input));
	}
}

int main() {
	findAns();
	return 0;
}