#include <iostream>
#include <string>
#define A 4
#define B 2
#define DOT '.'
using namespace std;

string str;

bool checkA(int cur) {
	for (int i = cur; i < cur + A; i++) {
		if (str[i] == DOT || i >= str.size()) return false;
	}
	return true;
}

bool checkB(int cur) {
	for (int i = cur; i < cur + B; i++) {
		if (str[i] == DOT || i >= str.size()) return false;
	}
	return true;
}

void install(int cur, int range, char type) {
	for (int i = cur; i < cur + range; i++) {
		str[i] = type;
	}
}

string findAns() {
	int i = 0;

	for (i = 0; i < str.size(); i++) {
		if (str[i] == DOT) continue;
		if (checkA(i)) {
			install(i, A, 'A');
			i += A - 1;
			continue;
		}
		if (checkB(i)) {
			install(i, B, 'B');
			i += B - 1;
			continue;
		}
		return "-1";
	}
	return str;
}

int main() {
	cin >> str;
	cout << findAns();
	return 0;
}
//string �Է� �ް�, �� �� �ε������� A ��ġ�� �� �ִ��� Ȯ��
//�ȵǸ� B ��ġ�� �� �ִ��� Ȯ��
//���� A,B �� �ϳ��� ��ġ�� �� �ִٸ�, ��ġ �� �� ���� �ε������� �� �۾� �ݺ�
//���� A,B �� �� ��ġ�� �ȵ� ��� -1 ���