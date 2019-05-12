#include <iostream>
using namespace std;

int x, total;

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> x;
		total += x;
	}

	int m = total / 60;
	int s = total % 60;

	cout << m << '\n' << s;
	return 0;
}

//분 : 전체 초를 60으로 나눈 몫
//초 : 전체 초를 60으로 나눈 나머지