#include <iostream>
#include <map>
#include <string>

using namespace std;
int N;
map<string, int> m;

void input() {
	cin >> N;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		m[name]++;
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> name;
		m[name]--;
	}
}

void findAns() {
	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second != 0) {
			cout << iter->first;
			return;
		}
	}
}

int main() {
	input();
	findAns();
	return 0;
}