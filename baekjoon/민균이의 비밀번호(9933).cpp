#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Ans
{
	int length;
	char mid;
};

int N;
vector<string> v;
Ans ans;

bool isPassword(string word) {
	string tmp = "";
	for (int i = word.size() - 1; i >= 0; i--) {
		tmp += word[i];
	}

	for (string word : v) {
		if (word == tmp) return true;
	}
	return false;
}

void findAns() {
	for (string word : v) {
		if (isPassword(word)) {
			ans.length = word.size();
			ans.mid = word[ans.length /2];
			return;
		}
	}
}

int main() {
	string input = "";
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	findAns();

	cout << ans.length << ' ' << ans.mid;
	return 0;
}