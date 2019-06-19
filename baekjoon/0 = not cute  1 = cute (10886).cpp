#include <iostream>
#include <string>
#define CUTE "Junhee is cute!"
#define NOTCUTE "Junhee is not cute!"
using namespace std;

int N;

string findAns() {
	int x, cute = 0;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x) cute++;
	}

	return cute > N - cute ? CUTE : NOTCUTE;
}

int main() {
	cin >> N;
	cout << findAns();
	return 0;
}