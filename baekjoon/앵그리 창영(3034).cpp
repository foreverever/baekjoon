#include <iostream>
#include <math.h>
#define DA "DA"
#define NE "NE"
using namespace std;

int N, h, v;

void findAns() {
	int mxLen = sqrt(h*h + v * v);
	int input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input <= mxLen) cout << DA << '\n';
		else cout << NE << '\n';
	}
}

int main() {
	cin >> N >> h >> v;
	findAns();
	return 0;
}