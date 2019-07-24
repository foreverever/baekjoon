#include <iostream>

using namespace std;

int tc;
bool isDuplicate[10];

void initDuplicate() {
	for (int i = 0; i < 10; i++) isDuplicate[i] = false;
}

void findAns(int testCase) {
	int num, cnt = 0;
	cin >> num;
	initDuplicate();

	while (num != 0) {
		if (!isDuplicate[num % 10]) {
			cnt++;
			isDuplicate[num % 10] = true;
		}
		num /= 10;
	}
	cout << "#" << testCase << ' ' << cnt << '\n';
}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		findAns(t);
	}
	return 0;
}