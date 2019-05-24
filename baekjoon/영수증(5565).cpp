#include <iostream>
#define MAX 9
using namespace std;

int total;

int findAns() {
	int n = 0;
	for (int i = 0; i < MAX; i++) {
		cin >> n;
		total -= n;
	}
	return total;
}

int main() {
	cin >> total;
	cout << findAns();
	return 0;
}