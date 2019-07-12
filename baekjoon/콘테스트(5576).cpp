#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> w, k;

void input() {
	int x;

	for (int i = 0; i < 20; i++) {
		cin >> x;
		if (i < 10) {
			w.push(x);
			continue;
		}
		k.push(x);
	}
}

void findAns() {
	int wAns = 0, kAns = 0;

	for (int i = 0; i < 3; i++) {
		wAns += w.top(); w.pop();
		kAns += k.top(); k.pop();
	}
	cout << wAns << ' ' << kAns;
}

int main() {
	input();
	findAns();
	return 0;
}