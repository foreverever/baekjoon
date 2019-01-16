#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int num, score;

void input() {
	int x;
	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> x;
			sum += x;
		}
		v.push_back(sum);
	}
}

void findAns() {
	for (int i = 0; i < v.size(); i++) {
		if (score < v[i]) {
			score = v[i];
			num = i + 1;
		}
	}
}

int main() {
	input();
	findAns();
	cout << num << ' ' << score;
	return 0;
}

///////////////////////////////////////////////pair »ç¿ë///////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
vector<pair<int, int> > v;

void findAns() {
	int x;
	for (int i = 0; i < 5; i++) {
		int s = 0;
		for (int j = 0; j < 4; j++) {
			cin >> x;
			s += x;
		}
		v.push_back({ s,i + 1 });
	}
	sort(v.begin(), v.end());
}

int main() {
	findAns();
	cout << v.back().second << ' ' << v.back().first;
	return 0;
}