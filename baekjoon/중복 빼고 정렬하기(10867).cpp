#include <iostream>
#include <set>
using namespace std;

int N;
set<int> s;

void findAns() {
	int x;

	for (int i = 0; i < N; i++) {
		cin >> x;
		s.insert(x);
	}
	set<int>::iterator iter;

	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	findAns();
	return 0;
}