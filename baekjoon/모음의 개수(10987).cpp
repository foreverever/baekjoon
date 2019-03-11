#include <iostream>
#include <string>
#include <map>

using namespace std;
map<char, bool> m;
int ans;
string str;

int main() {
	string vowels = "aeiou";
	for (char c : vowels) m[c] = true;
	cin >> str;
	for (char c : str) if (m.count(c)) ans++;
	cout << ans;
	return 0;
}
