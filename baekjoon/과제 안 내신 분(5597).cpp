#include <iostream>
#define MAX 28
using namespace std;

bool student[31];

void findAns() {
	int x;

	for (int i = 0; i < MAX; i++) {
		cin >> x;
		student[x] = true;
	}

	for (int i = 1; i <= MAX + 2; i++) {
		if (!student[i]) cout << i << '\n';
	}
}

int main() {
	findAns();
	return 0;
}