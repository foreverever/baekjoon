#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int L, C;
vector<char> alphabet;
unordered_map<char, bool> vowel;

void dfs(int idx, int cnt, int vowelCnt, int consonantCnt, string result) {
	if (cnt == L) {
		if (vowelCnt < 1 || consonantCnt < 2) return;
		cout << result << '\n';
		return;
	}

	for (int cur = idx; cur < C; cur++) {
		if (vowel.count(alphabet[cur])) {
			dfs(cur + 1, cnt + 1, vowelCnt + 1, consonantCnt, result + alphabet[cur]);
		}
		else dfs(cur + 1, cnt + 1, vowelCnt, consonantCnt + 1, result + alphabet[cur]);
	}
}

void initVowel() {
	vowel['a'] = true;
	vowel['e'] = true;
	vowel['i'] = true;
	vowel['o'] = true;
	vowel['u'] = true;
}

void findAns() {
	initVowel();

	char c;

	for (int i = 0; i < C; i++) {
		cin >> c;
		alphabet.push_back(c);
	}

	sort(alphabet.begin(), alphabet.end());

	dfs(0, 0, 0, 0, "");
}

int main() {
	cin >> L >> C;
	findAns();
	return 0;
}