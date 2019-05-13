//주어진 string 에 모든 단어를 거꾸로 하시오.
//예제)
//Input: “abc 123 apple”
//Output : “cba 321 elppa”

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string str;
vector<string> v;
stack<char> st;

void init() {
	string tmp = "";

	for (char c : str) {
		if (c == ' ') {
			v.push_back(tmp);
			tmp = "";
			continue;
		}
		tmp += c;
	}
	v.push_back(tmp);
}

void findAns() {
	for (string str : v) {
		for (int i = str.size() - 1; i >= 0; i--) {
			cout << str[i];
		}
		cout << ' ';
	}
}

void findAnsByStack() {
	for (char c : str) {
		if (c == ' ') {
			while (!st.empty()) {
				cout << st.top(); 
				st.pop();
			}
			cout << ' ';
			continue;
		}
		st.push(c);
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << ' ';
}

int main() {
	getline(cin, str);
	init();	//입력받은 문자열을 공백 기준으로 나눠 해당 단어를 string타입 벡터에 저장한다
	findAns();	//vector안의 단어들을 뒤집어서 출력
	
	findAnsByStack();	//stack 이용해서 출력
	return 0;
}