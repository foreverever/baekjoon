#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string toBinaryString(int num) {
	string s = "";

	while (num != 0) {
		s += to_string(num % 2);
		num /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

int solution(int N) {
	priority_queue<int> q;
	vector<int> dist;
	string str = toBinaryString(N);

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1') dist.push_back(i);
	}

	if (dist.size() >= 2) {
		for (int i = 0; i < dist.size() - 1; i++) {
			q.push(dist[i + 1] - dist[i] - 1);
		}
		return q.top();
	}
	return 0;
}

int main() {
	cout << solution(32);
	return 0;
}