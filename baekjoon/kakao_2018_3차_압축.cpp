#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> m;
map<string, int>::iterator iter;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int maxSize;
int start;

void initDictionary() {
	for (int i = 1; i <= alphabet.size(); i++) {
		string s(1, alphabet[i - 1]);
		m[s] = i;
	}
	maxSize = 26;
}

vector<int> solution(string msg) {
	initDictionary();
	vector<int> answer;
	for (int i = 0; i < msg.size(); i=start) {
		cout << "i : " << i << '\n';
		cout << "start : " << start << '\n';
		for (int j = 1; j < msg.size(); j++) {
			string str = msg.substr(start, j);
			if (m.count(str)) {
				continue;
			}
			else {
				answer.push_back(m[msg.substr(start, j - 1)]);	//이전 문자 값 저장
				m[str] = ++maxSize;
				start = i + j - 1;
				break;
			}
		}
	}
	return answer;
}

int main() {
	string msg = "TOBEORNOTTOBEORTOBEORNOT";
	vector<int> ans = solution(msg);
	//for (int val : ans) {
	//	cout << val << '\n';
	//}
	return 0;
}