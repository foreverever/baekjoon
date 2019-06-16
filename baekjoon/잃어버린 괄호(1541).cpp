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

// 1) string 을 int타입으로 parse하는 함수 구현
// 2) 이때, 추후 문제 해결을 편리하게 하기 위해 피연산자는 int타입 배열에, 연산자는 char타입 배열에 따로 저장하게끔 한다.
// 3) 맨처음 - 가 나오는 시점부터 그 뒤는 모두 - 처리하면 끝
