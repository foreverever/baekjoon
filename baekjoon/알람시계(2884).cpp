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

//�ʷ� �ٲ㼭 ���� �̿�
//-���� ������ ��� ���� �߰�