#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int N;
map<string, bool> m;

int main() {
	cin >> N;
	string str = "";

	for (int i = 0; i < N; i++) {
		cin >> str;
		sort(str.begin(), str.end());
		m[str] = true;
	}
	cout << m.size();

	return 0;
}