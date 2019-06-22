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
//string 입력 받고, 맨 앞 인덱스부터 A 설치할 수 있는지 확인
//안되면 B 설치할 수 있는지 확인
//만약 A,B 중 하나라도 설치할 수 있다면, 설치 후 그 다음 인덱스부터 위 작업 반복
//만약 A,B 둘 다 설치가 안될 경우 -1 출력