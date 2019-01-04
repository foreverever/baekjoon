#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
string s;
int sn, ans;
map<char, int> cnt;
vector<int> v;

int findAns() {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '6' || s[i] == '9') sn++;
		else cnt[s[i]]++;
	}
	map<char, int> ::iterator iter;
	for (iter = cnt.begin(); iter != cnt.end(); iter++) {
		v.push_back(iter->second);
	}
	if (!v.empty()) {
		sort(v.begin(), v.end());
		ans += v.back();
	}
	if (ans*2 >= sn) {
		return ans;
	}
	sn -= ans*2;
	return ans + (sn / 2 + sn % 2);
}

int main() {
	cin >> s;
	cout << findAns();
	return 0;
}