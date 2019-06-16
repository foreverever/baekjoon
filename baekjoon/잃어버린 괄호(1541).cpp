#include <iostream>
#include <string>
#include <vector>
#define PLUS '+'
#define MINUS '-'
using namespace std;

string str;
vector<int> number;
vector<char> op;

void parse() {
	string n = "";

	for (char c : str) {
		if (c == PLUS) {
			op.push_back(PLUS);
			number.push_back(atoi(n.c_str()));
			n = "";
		}
		else if (c == MINUS) {
			op.push_back(MINUS);
			number.push_back(atoi(n.c_str()));
			n = "";
		}
		else n += c;
	}
	number.push_back(atoi(n.c_str()));
}

int findAns() {
	int sum = number.front();
	bool chk = false;

	for (int i = 1; i < number.size(); i++) {
		if (chk) {
			sum -= number[i];
			continue;
		}
		if (op[i-1] == MINUS) {
			sum -= number[i];
			chk = true;
		}
		else {
			sum += number[i];
		}
	}
	return sum;
}

int main() {
	cin >> str;
	parse();
	cout << findAns();
	return 0;
}

// 1) string �� intŸ������ parse�ϴ� �Լ� ����
// 2) �̶�, ���� ���� �ذ��� ���ϰ� �ϱ� ���� �ǿ����ڴ� intŸ�� �迭��, �����ڴ� charŸ�� �迭�� ���� �����ϰԲ� �Ѵ�.
// 3) ��ó�� - �� ������ �������� �� �ڴ� ��� - ó���ϸ� ��
