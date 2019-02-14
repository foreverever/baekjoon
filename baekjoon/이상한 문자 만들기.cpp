#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<string> getVector(string s) {
	vector<string> v;
	string str = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			v.push_back(str);
			str = "";
			continue;
		}
		str += s[i];
	}
	v.push_back(str);
	return v;
}

string solution(string s) {
	string answer = "";
	vector<string> v = getVector(s);

	for (string str : v) {
		for (int i = 0; i < str.size(); i++) {
			if (i % 2 == 0) str[i] = toupper(str[i]);
			else str[i] = tolower(str[i]);
		}
		answer += str + ' ';
	}
	answer.pop_back();
	return answer;
}

int main() {
	string s = "try hello world";
	cout << solution(s);
	return 0;
}