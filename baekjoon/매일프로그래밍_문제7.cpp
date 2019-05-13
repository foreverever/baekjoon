//�־��� string �� ��� �ܾ �Ųٷ� �Ͻÿ�.
//����)
//Input: ��abc 123 apple��
//Output : ��cba 321 elppa��

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
	init();	//�Է¹��� ���ڿ��� ���� �������� ���� �ش� �ܾ stringŸ�� ���Ϳ� �����Ѵ�
	findAns();	//vector���� �ܾ���� ����� ���
	
	findAnsByStack();	//stack �̿��ؼ� ���
	return 0;
}