#include <iostream>
#include <vector>

using namespace std;

vector<int> number;

void init(int e) {
	int cnt = 1;
	while (number.size() <= e) {
		for (int i = 0; i < cnt; i++) {
			number.push_back(cnt);
		}
		cnt++;
	}
}

int findAns(int s, int e) {
	init(e);

	int sum = 0;
	for (int i = s - 1; i < e; i++) sum += number[i];
	return sum;
}

int main() {
	int s, e;
	cin >> s >> e;
	cout << findAns(s, e);
	return 0;
}