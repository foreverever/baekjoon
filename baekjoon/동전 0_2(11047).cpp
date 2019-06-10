#include <iostream>
#include <stack>
using namespace std;

int N, money;
stack<int> st;

void input() {
	cin >> N >> money;
	int x = 0;
	for (int i = 0; i < N; i++) {
		cin >> x;
		st.push(x);
	}
}

int findAns() {
	int ans = 0, target = 0;

	while (money) {
		target = st.top();
		if (money / target == 0) {
			st.pop();
			continue;
		}
		ans += money / target;
		money %= target;
	}
	return ans;
}

int main() {
	input();
	cout << findAns();
	return 0;
}