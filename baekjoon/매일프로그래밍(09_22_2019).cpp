//"./"�� "../" �� ���Ե� ���� ��θ� "./"�� "../"�� ���� ���н� ���� ��η� �ٲٽÿ�.
//"./"�� ������ ��ġ�� ���ϰ�, "../"�� ���� ���丮�� ���մϴ�.

//input: "/usr/bin/../"
//output : "/usr/"
//
//input : "/usr/./bin/./test/../"
//output : "/usr/bin/"

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

vector<string> split(string &str, char standard) {
	vector<string> v;
	string tmp = "";

	for (char c : str) {
		if (c == standard) {
			v.push_back(tmp);
			tmp = "";
			continue;
		}
		tmp += c;
	}
	v.push_back(tmp);
	return v;
}

void findAns(string &input) {
	stack<string> st, ans;
	vector<string> dir = split(input, '/');

	for (string s : dir) {
		if (s == "") continue;
		st.push(s);
	}
	while (!st.empty()) {
		string top = st.top(); st.pop();
		if (top == ".") continue;
		if (top == "..") st.pop();
		else ans.push(top);
	}

	while (!ans.empty()) {
		cout << '/' << ans.top();
		ans.pop();
	}
	cout << '/';
}

int main() {
	string input = "";
	cin >> input;
	findAns(input);
	return 0;
}