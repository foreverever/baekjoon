#include <iostream>
#include <string>

using namespace std;
string A, B;
int ans = 2e9;

void calcDiff(string b) {
	int cnt = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] != b[i]) cnt++;
	}
	ans = cnt < ans ? cnt : ans;
}
void findAns() {
	string b;
	int range = B.size() - A.size();
	for (int i = 0; i <= range; i++) {
		b = B.substr(i, A.size());
		calcDiff(b);
	}
}

int main() {
	cin >> A >> B;
	findAns();
	cout << ans;
	return 0;
}