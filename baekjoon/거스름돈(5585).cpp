#include <iostream>
#include <vector>
#define PAY 1000
using namespace std;

int n, ans;
vector<int> v = { 500,100,50,10,5,1 };

int calc(int change, int coin) {
	int cnt = change / coin;
	ans += cnt;
	return change - (cnt*coin);
}

int findAns(int change) {
	for (int val : v) {
		change = calc(change, val);
	}
	return ans;
}

int main() {
	cin >> n;
	findAns(PAY - n);
	cout << ans;
	return 0;
}