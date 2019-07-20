#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

bool isExist[101];

int calcCount(queue<int> &q) {
	int cnt = 0, val;

	while (!q.empty()) {
		val = q.front(); q.pop();
		if (isExist[val * 2]) cnt++;
	}
	return cnt;
}

void findAns() {
	int x = 101;
	queue<int> q;

	while (1) {
		while (1) {
			cin >> x;
			if (x == -1) return;
			if (x == 0) break;
			q.push(x);
			isExist[x] = true;
		}
		cout << calcCount(q) << '\n';
		memset(isExist, false, sizeof(isExist));
	}
}

int main() {
	findAns();
	return 0;
}