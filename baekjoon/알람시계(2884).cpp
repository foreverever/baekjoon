#include <iostream>
#define SUB 45
#define MAXMINUTE 60
using namespace std;

int h, m;

void findAns() {
	int total = h * MAXMINUTE + m;
	total -= SUB;
	if (total < 0) {
		cout << 23 << ' ' << MAXMINUTE + total;
		return;
	}
	cout << total / MAXMINUTE << ' ' << total % MAXMINUTE;
}

int main() {
	cin >> h >> m;
	findAns();
	return 0;
}

//초로 바꿔서 뺄셈 이용
//-값이 나오는 경우 조건 추가