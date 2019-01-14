#include <iostream>
#include <stack>
#include <string>

using namespace std;
int N, ans;
string word;

void findAns() {
	for (int i = 0; i < N; i++) {
		stack<char> st;
		cin >> word;
		for (char var : word) {
			if (st.empty()) {
				st.push(var);
				continue;
			}
			if (st.top() == var) {
				st.pop();
			}
			else {
				st.push(var);
			}
		}
		if (st.empty()) {
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	findAns();
	cout << ans;
	return 0;
}